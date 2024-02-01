#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    double z = (double) x / (double) y;
    printf("%.20f\n", z);
}
