#include <cs50.h>
#include <stdio.h>

// Prototype
void print_row(int spaces, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height from one to eight
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Variable to control the number of spaces
    int spaces = n - 1;

    // Print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        print_row(spaces, i + 1);
        spaces--;
    }
}

void print_row(int spaces, int bricks)
{
    // Print spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // Print bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
