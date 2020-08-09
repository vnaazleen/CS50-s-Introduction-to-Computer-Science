#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height;

    do
    {
        // Get Height
        height = get_int("Height :");

    }
    while (height > 8 || height < 1);

    for (int h = 0; h < height; ++h)
    {
        // For spaces
        for (int s = 0; s < height - h - 1; ++s)
        {
            printf(" ");
        }

        // For characters
        for (int c = 0; c <= h ; ++c)
        {
            printf("#");
        }

        printf("  ");

        for (int c = 0; c <= h; ++c)
        {
            printf("#");
        }

        // For new line character
        printf("\n");
    }

    return 0;

}
