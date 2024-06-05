import re
from cs50 import get_string


def main():
    # Get user input for credit card number
    credit_card = get_string("Number: ")

    # Check if the input is a sequence of digits of length 13 to 16
    if re.match(r"^\d{13,16}$", credit_card):
        # Validate the credit card number
        if is_valid_credit_card(credit_card):
            # Determine the card type and print it
            print(get_card_type(credit_card))
        else:
            # If not valid, print "INVALID"
            print("INVALID")
    else:
        # If not a valid sequence of digits, print "INVALID"
        print("INVALID")


def is_valid_credit_card(credit_card):
    """Check if a credit card is valid using Luhn's algorithm."""
    digits = [int(d) for d in str(credit_card)]
    checksum = 0
    for i, digit in enumerate(digits[::-1]):
        if i % 2 == 0:
            checksum += digit
        else:
            checksum += sum(divmod(digit * 2, 10))
    return checksum % 10 == 0


def get_card_type(credit_card):
    """Determine the card type based on the provided rules."""
    num_digits = len(str(credit_card))
    first_two_digits = int(str(credit_card)[:2])
    if num_digits == 15 and first_two_digits in [34, 37]:
        return "AMEX"
    elif num_digits == 16 and 51 <= first_two_digits <= 55:
        return "MASTERCARD"
    elif num_digits in [13, 16] and str(credit_card)[0] == "4":
        return "VISA"
    else:
        return "INVALID"


if __name__ == "__main__":
    main()
