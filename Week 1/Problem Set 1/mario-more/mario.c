#include <cs50.h>
#include <stdio.h>

// Prototype
void print_row(int left_spaces, int left_pyramid_bricks, int middle_spaces, int right_pyramid_bricks);

int main(void)
{
    // Prompt the user for the pyramid's height from one to eight
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Variable to control the number of spaces for right pyramid
    int left_spaces = n - 1;

    // Setting number of middle spaces
    int middle_spaces = 2;

    // Print two pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        print_row(left_spaces, i + 1, middle_spaces, i + 1);
        left_spaces--;
    }
}

void print_row(int left_spaces, int left_pyramid_bricks, int middle_spaces, int right_pyramid_bricks)
{
    // Print left spaces
    for (int i = 0; i < left_spaces; i++)
    {
        printf(" ");
    }

    // Print left pyramid bricks
    for (int i = 0; i < left_pyramid_bricks; i++)
    {
        printf("#");
    }

    // Print middle spaces
    for (int i = 0; i < middle_spaces; i++)
    {
        printf(" ");
    }

    // Print right pyramid bricks
    for (int i = 0; i < right_pyramid_bricks; i++)
    {
        printf("#");
    }

    // Print a newline to move to the next row
    printf("\n");
}
