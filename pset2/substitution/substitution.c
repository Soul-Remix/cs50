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
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(key);

    // check if the argument is not a number
    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Prompt to get the plain text
    string text = get_string("plaintext: ");

    // the text length
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        // Check if the char is upper case
        if (isupper(text[i]))
        {
            int n = ((int)(text[i]) - 65);
            char m = key[n];
            text[i] = toupper(m);
        }
        // Check if the char is lower case
        else if (islower(text[i]))
        {
            int n = ((int)(text[i]) - 97);
            char m = key[n];
            text[i] = tolower(m);
        }
    }

    // Return the cipherd text
    printf("ciphertext: %s\n", text);
}