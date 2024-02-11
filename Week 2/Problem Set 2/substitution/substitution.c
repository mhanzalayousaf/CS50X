#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get the key from command-line argument
    string key = argv[1];

    // Check if the key is valid
    if (!is_valid_key(key))
    {
        printf("Invalid key. The key must contain 26 unique alphabetical characters.\n");
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // Encrypt and print ciphertext
    printf("ciphertext: ");
    encrypt(plaintext, key);
    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    int len = strlen(key);

    // Check if the key has 26 characters
    if (len != 26)
    {
        return false;
    }

    // Check if each character is an alphabetical character
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    // Check if each letter appears exactly once in the key
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                return false;
            }
        }
    }

    return true;
}

void encrypt(string plaintext, string key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char current_char = plaintext[i];

        // Check if the character is alphabetical
        if (isalpha(current_char))
        {
            char case_adjust = isupper(current_char) ? 'A' : 'a';

            // Find the index of the character in the alphabet
            int index = current_char - case_adjust;

            // Replace the character with the corresponding key character
            printf("%c", isupper(current_char) ? toupper(key[index]) : tolower(key[index]));
        }
        else
        {
            // Print non-alphabetical characters unchanged
            printf("%c", current_char);
        }
    }
}
