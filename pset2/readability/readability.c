#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    // Initial values
    int letters = 0;
    float words = 1;
    float sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check for letters in the text
        if ((text[i] >= 97 && text[i] <= 122) ||
            (text[i] >= 65 && text[i] <= 90))
        {
            letters++;
        }

        // Check for words in the text
        if (text[i] == 32)
        {
            words++;
        }

        // Check for sentences in the text
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }

    // Calculate average number of letters & sentences per 100 words
    float L = 100 * (letters / words);
    float S = 100 * (sentences / words);

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}