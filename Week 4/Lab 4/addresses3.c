#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c", *s); // printf("%c", s[0]);
    printf("%c", *(s + 1)); // printf("%c", s[1]);
    printf("%c\n", *(s + 2)); // printf("%c\n", s[2]);
}
