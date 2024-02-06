#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./mario number");
    }

    int height = atoi(argv[1]);

    for (int i = 0; i < height; i++)
    {
        print_row(i + 1);
    }
}

void print_row(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("#");
    }
    printf("\n");
}
