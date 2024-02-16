#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./pdf Filename(.pdf or .jpg)\n");
        return 1;
    }

    // Check first four bytes in the given file
    string filename = argv[1];
    FILE *f = fopen(filename, "r");
    uint8_t buffer[4];
    fread(buffer, 1, 4, f);

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }
    fclose(f);
    return 0;
}
