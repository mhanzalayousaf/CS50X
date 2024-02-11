#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Print the label before the loop
    printf("ciphertext: ");

    // For each character in the plaintext:
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Rotate the character if it's a letter
        char ciphertext = rotate(plaintext[i], key);

        // Print the rotated character
        printf("%c", ciphertext);
    }

    printf("\n"); // Add a newline after processing all characters

    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    // Check if the character is a lowercase letter
    if (islower(c))
    {
        // Rotate the lowercase letter by n positions
        return 'a' + (c - 'a' + n) % 26;
    }
    // Check if the character is an uppercase letter
    else if (isupper(c))
    {
        // Rotate the uppercase letter by n positions
        return 'A' + (c - 'A' + n) % 26;
    }
    // If the character is not a letter, return it unchanged
    else
    {
        return c;
    }
}
