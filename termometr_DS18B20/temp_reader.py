# requires pyserial
# python -m pip install pyserial

import sys
import serial
import logging
import serial.tools.list_ports as lp


logger = logging.getLogger('temp_logger')
logger.setLevel(logging.INFO)

#file  handler
fh = logging.FileHandler('temp.log')

# console handler
ch = logging.StreamHandler(sys.stdout)
console_formatter = logging.Formatter('%(asctime)s: Temp: %(message)s')
file_formatter = logging.Formatter('"%(asctime)s","%(message)s"')

ch.setFormatter(console_formatter)
fh.setFormatter(file_formatter)

logger.addHandler(ch)
logger.addHandler(fh)

BAUD_RATE = 9600

ports = lp.comports()

arduinos = filter(lambda port_info: 'arduino' in port_info.description.lower(), ports)

if not arduinos:
    sys.exit(1)

arduino = next(arduinos)
with serial.Serial(arduino.device, BAUD_RATE) as ser:
    while True:
        try:
            line = ser.readline().decode('utf-8').strip()
            logger.info(line)
        except KeyboardInterrupt:
            res = input('Do you really want to exit? [yn] ')
            if res == 'y' or res == 'yes':
                sys.exit(0)
            else:
                continue
