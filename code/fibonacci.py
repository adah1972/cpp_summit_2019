from __future__ import print_function
from itertools import islice, takewhile


def fibonacci():
    a = 0
    b = 1
    while True:
        yield b
        a, b = b, a + b


def main():
    # Print first 20 numbers in the sequence
    for i in islice(fibonacci(), 20):
        print(i)

    # Print all numbers in the sequence that are less than 10000
    for i in takewhile(lambda x: x < 10000, fibonacci()):
        print(i)


if __name__ == '__main__':
    main()
