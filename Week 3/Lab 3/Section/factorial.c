#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int number;
    do
    {
        number = get_int("Number: ");
    }
    while (number < 0);
    printf("Factorial: %i\n", fact(number));
}

int fact(int n)
{
    // Base case
    if (n == 1 | n == 0)
    {
        return 1;
    }

    // Recursive case
    return n * fact(n - 1);
}
