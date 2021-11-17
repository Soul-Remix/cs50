#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    
    //Prompt for pyramid height
    int height;
    do 
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    for (int i = 0; i < height; i++) 
    {
        // Print empty spaces 
        for (int j = 1; j < height - i; j++) 
        {
            printf(" ");
        }
    
        // Print the blocks for the left size
        for (int j = 0; j <= i; j++) 
        {
            printf("#");
        }
       
        // Print the space between the two sides
        printf("  ");
       
        // Print the blocks for the right size
        for (int j = 0; j <= i; j++) 
        {
            printf("#");
        }
       
        // Print a new line
        printf("\n");
    }
}