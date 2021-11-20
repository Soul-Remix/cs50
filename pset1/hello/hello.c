#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get the user name
    string name = get_string("Name: ");
    // Print Hello World to the console
    printf("%s\n", name);
}