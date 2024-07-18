import dis
from types import CellType


def outer():
    n = 100

    def inner():
        nonlocal n
        print((lambda: n)())

    return inner


def f():
    n = 2
    exec(outer().__code__, closure=(CellType(n),))


f()
