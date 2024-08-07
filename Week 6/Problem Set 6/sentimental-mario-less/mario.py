from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if 0 < height < 9:
            break

    pyramid(height)


def pyramid(n):
    s = n - 1
    for i in range(n):
        print(' ' * s, '#' * (i + 1), sep='')
        s -= 1


if __name__ == "__main__":
    main()
