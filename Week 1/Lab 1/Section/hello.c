#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string first_name = get_string("What's your first name? ");
    string second_name = get_string("What's your second name? ");
    printf("Hello, %s %s\n", first_name, second_name);
}
