from serial.tools import list_ports

from utils.logger import Logger
import Device


def find_arduino():
    """Find Arduino in available COM ports
    :return first port object connected to arduino board"""
    ports = list_ports.comports()

    # search for Arduino in available ports
    while ports:
        device = Device.Device(ports.pop())

        # select first found Arduino
        if 'arduino' in device.name.lower():
            print('Arduino found in port {}'.format(device.device))
            return device

    # if Arduino not found - return nothing
    print('\nArduino not found')
    return None
