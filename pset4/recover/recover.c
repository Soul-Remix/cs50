#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }
    
    BYTE buffer[512];
    int count = 0;
    FILE *img = NULL;
    char filename[8];
    
    while (fread(&buffer, 512, 1, card) == 1)
        {
            // If start of a new JPEG (0xff 0xd8 0xff 0xe*):
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                // If not first JPEG, close previous
                if (count != 0)
                {
                    fclose(img);
                }
                // Initialise file
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                count++;
            }
            // If JPEG has been found, write to file
            if (count != 0)
            {
                fwrite(&buffer, 512, 1, img);
            }
        }
        fclose(card);
        fclose(img);
        return 0;
}