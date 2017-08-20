from enum import Enum


class OS(Enum):
    WINDOWS = 'Windows'
    LINUX = 'Linux'
    UNKNOWN = object()

    @staticmethod
    def get_system(sys):
        """Switch statement to find operating system
        :return os enum"""
        return {
            'Windows': OS.WINDOWS,
            'Linux': OS.LINUX
        }.get(sys, OS.UNKNOWN)
