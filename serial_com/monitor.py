#!/usr/bin/env python3

import platform
from serial.tools import list_ports

import Device
from op_sys import OS

system = OS.get_system(platform.system())

ports = list_ports.comports()

devices = []

for port in ports:
    device = Device.Device(port)
    device.print_info()
    devices.append(device)
