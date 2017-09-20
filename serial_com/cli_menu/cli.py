#!/usr/bin/env python3
# https://pypi.python.org/pypi/Menu

from cli_menu import menu

menu_ = menu.Menu(title='Example menu')

handler1 = lambda: print('xxx')
menu_.options = [
    ('Print xxx', handler1),
    ('Print yyy', lambda: print('yyy')),
    ('Close', menu.Menu.CLOSE)
]

menu_.open()
