#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8

typedef uint8_t BYTE;

bool is_jpg(BYTE[]);

int main(int argc, char *argv[])
{
    // Program shd take only one command line arg
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Declare a file pointer
    FILE *infile;

    // Check whether the file exists or not
    if (!(infile = fopen(argv[1], "r")))
    {
        printf("Please! Provide a existing filename.\n");
        return 1;
    }

    // 0xff 0xd8 0xff 0xe[1-f] -> jpg header
    BYTE buffer[BLOCK_SIZE];

    bool found_jpg = false;
    int file_index = 0;
    FILE *outfile;
    while (fread(buffer, BLOCK_SIZE, 1, infile))
    {
        // Find whether we found a jpg or not
        if (is_jpg(buffer))
        {
            if (!found_jpg)
            {
                found_jpg = true;
            }
            else
            {
                fclose(outfile);
            }

            char filename[FILE_NAME_SIZE];
            // Create a file
            sprintf(filename, "%03i.jpg", file_index++);
            // Open the file
            outfile = fopen(filename, "w");
            // Check if the file created or not
            if (outfile == NULL)
            {
                return 1;
            }
            // write the previous contents to the file
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
        else if (found_jpg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }


    // Close a files
    fclose(infile);
    fclose(outfile);

    return 0;
}

bool is_jpg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0);
}