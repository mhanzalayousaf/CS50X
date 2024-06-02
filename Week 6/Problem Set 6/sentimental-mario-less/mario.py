from cs50 import get_int


def main():
    # Prompt the user for the pyramid's height
    height = get_int("Height: ")
    while height < 1 or height > 8:
        height = get_int("Height: ")

    # Print a pyramid of that height
    print_pyramid(height)


def print_pyramid(n):
    """Print a pyramid of given height."""
    for i in range(1, n + 1):
        # Print spaces
        print(" " * (n - i), end="")

        # Print bricks
        print("#" * i)


if __name__ == "__main__":
    main()
