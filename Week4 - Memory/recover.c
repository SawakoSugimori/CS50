// This is a program that recovers JPEGs from a forensic image.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open memory card
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int filenumber = 0;
    char filename[8];

    FILE *img = NULL;

    // A flag for checking whether JEPG file is found or not
    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        // Read 512 bytes into a buffer
        // fread(buffer, 512, 1, inptr);

        // If there are the first three bytes of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If first JPEG
            if (filenumber == 0)
            {
                // Start writing 000.jpeg
                sprintf(filename, "%03i.jpg", filenumber);
                img = fopen(filename, "w");
                fwrite(&buffer, 1, BLOCK_SIZE, img);
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", filenumber);
                img = fopen(filename, "w");
                fwrite(&buffer, 1, BLOCK_SIZE, img);
            }
            filenumber++;
        }
        // If already found JPEG
        else if (filenumber > 0)
        {
            // Keep writing JPEG
            fwrite(&buffer, 1, BLOCK_SIZE, img);
        }
    }

    // Close any remaining files
    fclose(inptr);
    fclose(img);
}
