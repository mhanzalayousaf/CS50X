from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if 0 < height < 9:
            break

    pyramids(height)


def pyramids(n):
    s = n - 1
    for i in range(1, n + 1):
        print(" " * s, "#" * i, "  ", "#" * i, sep="")
        s -= 1


if __name__ == "__main__":
    main()
