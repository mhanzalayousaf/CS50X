#include <stdio.h>

void meaw(int n);

int main(void)
{
    meaw(30000);
}

void meaw(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meaw\n");
    }
}
