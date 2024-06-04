from cs50 import get_float


def main():
    # Prompt the user for the amount of change owed
    dollars = get_float("Change: ")
    while dollars < 0:
        dollars = get_float("Change: ")

    # Convert dollars to cents
    cents = round(dollars * 100)

    # Print the total number of coins
    print(calculate_coins(cents))


def calculate_coins(cents):
    """Calculate the total number of coins needed."""

    quarters = cents // 25
    dimes = (cents % 25) // 10
    nickels = ((cents % 25) % 10) // 5
    pennies = ((cents % 25) % 10) % 5

    total_coins = quarters + dimes + nickels + pennies
    return total_coins


if __name__ == "__main__":
    main()
