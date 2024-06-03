from cs50 import get_int


def main():
    # Prompt the user for the pyramid's height
    height = get_int("Height: ")
    while height < 1 or height > 8:
        height = get_int("Height: ")

    # Print the pyramids of that height
    print_pyramids(height)


def print_pyramids(n):
    """Print the pyramids of given height."""
    for i in range(n):
        # Print left spaces
        print(" " * (n - i - 1), end="")

        # Print left pyramid bricks
        print("#" * (i + 1), end="")

        # Print middle spaces
        print("  ", end="")

        # Print right pyramid bricks
        print("#" * (i + 1))


if __name__ == "__main__":
    main()
