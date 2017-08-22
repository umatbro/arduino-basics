#!/usr/bin/env python3

import serial
import sys
import os

from utils.logger import Logger
from utils.connect import find_arduino

BAUD_RATE = 9600
BASE_DIR = os.path.join(os.path.dirname(__file__))

# search for Arduino in available ports
device = find_arduino()

if not device:
    sys.exit()

# start listening on port
arduino = serial.Serial(
    port=device.device,
    baudrate=BAUD_RATE,
)

logger = Logger(os.path.join(BASE_DIR, '22.08'))

while True:
    try:
        line = arduino.readline()
        if line:
            logger.log(line.decode('UTF-8').strip())

    except KeyboardInterrupt:
        print('Keyboard interrupt. Exiting program')
        sys.exit()
