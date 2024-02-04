#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Prototype
bool is_valid_credit_card(long credit_card);
int get_card_type(long credit_card);

int main(void)
{
    // Prompt the user for a credit card number
    long credit_card = get_long("Credit Card: ");

    // Check if the credit card is valid
    if (is_valid_credit_card(credit_card))
    {
        // Determine and print the card type
        int card_type = get_card_type(credit_card);

        // Print the result based on card type
        switch (card_type)
        {
            case 1:
                printf("AMEX\n");
                break;
            case 2:
                printf("MASTERCARD\n");
                break;
            case 3:
                printf("VISA\n");
                break;
            default:
                printf("INVALID\n");
                break;
        }
    }
    else
    {
        // Print INVALID if the credit card is not valid
        printf("INVALID\n");
    }

    // Return 0 to indicate successful execution
    return 0;
}

// Function to check if a credit card is valid using Luhn's algorithm
bool is_valid_credit_card(long credit_card)
{
    int sum = 0;
    bool is_alternate_digit = false;

    // Iterate through each digit of the credit card number
    while (credit_card > 0)
    {
        // Extract the last digit
        int digit = credit_card % 10;

        // Apply Luhn's algorithm
        if (is_alternate_digit)
        {
            digit *= 2;
            sum += (digit % 10) + (digit / 10);
        }
        else
        {
            sum += digit;
        }

        // Toggle is_alternate_digit for the next iteration
        is_alternate_digit = !is_alternate_digit;

        // Move to the next digit
        credit_card /= 10;
    }

    // The credit card is valid if the sum's last digit is 0
    return (sum % 10 == 0);
}

// Function to determine the card type based on the provided rules
int get_card_type(long credit_card)
{
    // Calculate the number of digits in the credit card number using a loop
    int num_digits = 0;
    long temp = credit_card;

    while (temp != 0)
    {
        temp /= 10;
        num_digits++;
    }

    // Extract the first two digits
    int first_two_digits = credit_card / pow(10, num_digits - 2);

    // Check the rules to determine the card type
    if (num_digits == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        return 1; // AMEX
    }
    else if (num_digits == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        return 2; // MASTERCARD
    }
    else if ((num_digits == 13 || num_digits == 16) && first_two_digits / 10 == 4)
    {
        return 3; // VISA
    }
    else
    {
        return 0; // INVALID
    }
}
