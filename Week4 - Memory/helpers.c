// This is a program that applies filters, grayscale, sepia, reverse and blur, to BMPs.
#include "helpers.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalBlue, originalGreen;
    for (int i = 0; i < abs(height); i++)
    {
        for (int j = 0; j < abs(width); j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            // Caluclate the average of three values
            int avg = round((originalRed + originalGreen + originalBlue) / (float)3);
            // printf("%i\n", avg);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalBlue, originalGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            // Caluclate the sepia colors
            int sepiaRed, sepiaGreen, sepiaBlue;
            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Check if the sepia colors are more than 255 or not
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < abs(height); i++)
    {
        for (int j = 0; j < abs(width) / 2; j++)
        {
            int tmpRed = 0, tmpGreen = 0, tmpBlue = 0;

            // Swap values
            tmpRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = tmpRed;

            tmpGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = tmpGreen;

            tmpBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = tmpBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Copy the original pixels
            copy[h][w].rgbtRed = image[h][w].rgbtRed;
            copy[h][w].rgbtGreen = image[h][w].rgbtGreen;
            copy[h][w].rgbtBlue = image[h][w].rgbtBlue;
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int availables = 0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    // Make sure h + i is above 0 and below height, w + j is above 0 and below width
                    if ((h + i >= 0 && h + i < height) && (w + j >= 0 && w + j < width))
                    {
                        // Count the number of available pixcels
                        availables++;
                        // Sum up all values
                        sumRed += copy[h + i][w + j].rgbtRed;
                        sumGreen += copy[h + i][w + j].rgbtGreen;
                        sumBlue += copy[h + i][w + j].rgbtBlue;
                    }
                }
            }
            // Caluculate blur values
            image[h][w].rgbtRed = round(sumRed / (float)availables);
            image[h][w].rgbtGreen = round(sumGreen / (float)availables);
            image[h][w].rgbtBlue = round(sumBlue / (float)availables);


        }
    }
    return;
}
