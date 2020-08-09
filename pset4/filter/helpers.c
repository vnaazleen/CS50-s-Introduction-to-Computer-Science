#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //declare a variable average to store the average colour
    float average;
    //loop through image rows
    for (int i = 0; i < height; i++)
    {
        //loop through image pixels
        for (int j = 0; j < width; j++)
        {
            //calculate average value for each pixel
            average = 1.0 * (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            //assign the average value to all values of each pixel
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);
        }
    }
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE byte;
    for (int i = 0; i < height; ++i)
    {
        int sepiaBlue, sepiaGreen, sepiaRed;
        for (int j = 0; j < width; ++j)
        {
            byte = image[i][j];
            // Formula for sepia red
            sepiaRed = (int)round(0.393 * byte.rgbtRed + 0.769 * byte.rgbtGreen + 0.189 * byte.rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            // Formula for sepia green
            sepiaGreen = (int)round(0.349 * byte.rgbtRed + 0.686 * byte.rgbtGreen + 0.168 * byte.rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            // Formula for sepia blue
            sepiaBlue = (int)round(0.272 * byte.rgbtRed + 0.534 * byte.rgbtGreen + 0.131 * byte.rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp;
    // swap the left pixels with right pixels
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0, k = width - 1; j < width / 2; ++j, --k)
        {
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][k].rgbtBlue;
            image[i][k].rgbtBlue = temp;

            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][k].rgbtGreen;
            image[i][k].rgbtGreen = temp;

            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][k].rgbtRed;
            image[i][k].rgbtRed = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //initialise a variable average for each colour, a new array to copy to and a counter
    float averageGreen;
    float averageRed;
    float averageBlue;
    RGBTRIPLE image2[height][width];
    int count;

    //loop through array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //set counter and averages to 0
            count = 0;
            averageBlue = 0;
            averageGreen = 0;
            averageRed = 0;
            //loop to get pixels above and below height
            for (int r = i - 1; r <= i + 1 && r < height; r++)
            {
                //if index out of bounds make it 0
                if (r < 0)
                {
                    continue;
                }

                //loop to get pixels to the left and right of width
                for (int c = j - 1; c <= j + 1 && c < width; c++)
                {
                    //if index out of bounds make it 0
                    if (c < 0)
                    {
                        continue;
                    }

                    //add values to the average and increment count
                    averageBlue += image[r][c].rgbtBlue;
                    averageGreen += image[r][c].rgbtGreen;
                    averageRed += image[r][c].rgbtRed;
                    count++;
                }
            }
            //udpdate copy array with average values divided by counter
            image2[i][j].rgbtBlue = round(averageBlue / count);
            image2[i][j].rgbtGreen = round(averageGreen / count);
            image2[i][j].rgbtRed = round(averageRed / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image2[i][j];
        }
    }
}
