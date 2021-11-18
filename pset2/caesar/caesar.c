#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if there's more than one argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // check if the argument is not a number
    if (!atoi(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);

    // Prompt to get the plain text
    string text = get_string("plaintext: ");

    // the text length
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        // Check if the char is upper case
        if (isupper(text[i]))
        {
            int n = (((int)(text[i]) - 65 + key) % 26) + 65;
            text[i] = (char)n;
        }
        // Check if the char is lower case
        else if (islower(text[i]))
        {
            int n = (((int)(text[i]) - 97 + key) % 26) + 97;
            text[i] = (char)n;
        }
    }

    // Return the cipherd text
    printf("ciphertext: %s\n", text);
}