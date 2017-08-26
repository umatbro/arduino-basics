import os
from time import time


class Logger:
    def __init__(self, log_path):
        # get absolute path of the logfile
        if not os.path.isabs(log_path):
            log_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), log_path)

        self.__log_path = '{}.xd'.format(log_path)

    def log(self, message):
        with open(self.__log_path, 'a') as f:
            f.write(self.message_with_timestamp(message) + '\n')

    def log_and_print(self, message):
        """Write given message on the screen as well save it to file (with timestamp)"""
        self.log(message)

        print('> {}'.format(message))

    @staticmethod
    def message_with_timestamp(message):
        """:return given message with timestamp formatted like this:
        123456.123 message_after_timestamp"""
        return '{:.3f} {}'.format(time(), message)
