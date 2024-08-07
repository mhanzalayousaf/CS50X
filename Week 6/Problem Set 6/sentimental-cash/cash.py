from cs50 import get_float


def main():
    while True:
        change = get_float("Change: ")*100
        if change > 0:
            break

    quarters = calculate_quarters(change)
    change -= (quarters * 25)
    dimmes = calculate_dimmes(change)
    change -= (dimmes * 10)
    nickles = calculate_nickles(change)
    change -= (nickles * 5)
    pennies = calculate_pennies(change)
    change -= pennies

    counts = quarters + dimmes + nickles + pennies
    print(counts)


def calculate_quarters(cents):
    quarters = 0
    while cents >= 25:
        quarters += 1
        cents -= 25
    return quarters


def calculate_dimmes(cents):
    dimmes = 0
    while cents >= 10:
        dimmes += 1
        cents -= 10
    return dimmes


def calculate_nickles(cents):
    nickles = 0
    while cents >= 5:
        nickles += 1
        cents -= 5
    return nickles


def calculate_pennies(cents):
    pennies = 0
    while cents >= 1:
        pennies += 1
        cents -= 1
    return pennies


if __name__ == "__main__":
    main()
