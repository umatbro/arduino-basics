class Device:
    """Class to represent device connected to the serial port"""
    def __init__(self, port):
        """:param port found by serial.tools.list_ports"""
        self.device = None
        self.name = None
        self.vid = None
        self.pid = None
        self.serial_number = None
        self.interface = None

        if port.device is not None:
            self.device = port.device
            self.name = port.description
            self.vid = port.vid
            self.pid = port.pid
            self.serial_number = port.serial_number
            self.interface = port.interface

    def print_info(self):
        print(('''Device: {}
            description: {}
            vid: {}
            pid: {}
            serial_number: {}
            interface: {}'''.format(
            self.device,
            self.name,
            self.vid,
            self.pid,
            self.serial_number,
            self.interface
        )))

    def __str__(self):
        result = str(self.device)
        if self.pid is not None:
            return result + ' {} (pid: {})'.format(self.name, self.pid)
        else:
            return result + ' no device'
