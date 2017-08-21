#!/usr/bin/env python3

import serial
from serial.tools import list_ports
import sys
from utils.connect import find_arduino

BAUD_RATE = 9600

ports = list_ports.comports()

# search for Arduino in available ports
device = find_arduino()

if not device:
    sys.exit()

# start listening on port
arduino = serial.Serial(
    port=device.device,
    baudrate=BAUD_RATE,
)

while True:
    try:
        line = arduino.readline()
        if line:
            print(line.decode('UTF-8').strip())

    except KeyboardInterrupt:
        print('Stopped listening. Exitting program')
        sys.exit()
