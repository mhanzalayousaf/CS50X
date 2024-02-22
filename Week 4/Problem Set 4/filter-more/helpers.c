#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average of red, green, and blue
            int averageRGB = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Update pixel values
            image[i][j].rgbtRed = averageRGB;
            image[i][j].rgbtGreen = averageRGB;
            image[i][j].rgbtBlue = averageRGB;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary array to store pixels
    RGBTRIPLE temp[height][width];

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        // Check if the width is even or odd
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                // Swap pixels
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
        else
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                // Swap pixels
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image
    RGBTRIPLE copy[height][width];

    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize sum and count for averaging
            int sumRed = 0, sumGreen = 0, sumBlue = 0, count = 0;

            // Iterate over the 3x3 box around the pixel
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    // Calculate the neighbor's position
                    int neighborRow = i + k;
                    int neighborCol = j + l;

                    // Check if the neighbor is within or outside the image boundaries
                    if (neighborRow >= 0 && neighborRow < height && neighborCol >= 0 && neighborCol < width)
                    {
                        // Update the sum of color values and increment count
                        sumRed += image[neighborRow][neighborCol].rgbtRed;
                        sumGreen += image[neighborRow][neighborCol].rgbtGreen;
                        sumBlue += image[neighborRow][neighborCol].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average color values for the pixel
            copy[i][j].rgbtRed = round((float) sumRed / count);
            copy[i][j].rgbtGreen = round((float) sumGreen / count);
            copy[i][j].rgbtBlue = round((float) sumBlue / count);
        }
    }

    // Copy the blurred image back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image to store the updated pixels
    RGBTRIPLE temp[height][width];

    // Define the Sobel operator kernels for edge detection
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize gradients for each color channel
            int gxBlue = 0, gyBlue = 0, gxGreen = 0, gyGreen = 0, gxRed = 0, gyRed = 0;

            // Apply the Sobel operator to calculate the gradients
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    int neighborRow = i + r;
                    int neighborCol = j + c;

                    // Skip pixels outside the image boundaries
                    if (neighborRow < 0 || neighborRow >= height || neighborCol < 0 || neighborCol >= width)
                    {
                        continue;
                    }

                    // Update the gradients using the Sobel kernels
                    gxBlue += image[neighborRow][neighborCol].rgbtBlue * gx[r + 1][c + 1];
                    gyBlue += image[neighborRow][neighborCol].rgbtBlue * gy[r + 1][c + 1];
                    gxGreen += image[neighborRow][neighborCol].rgbtGreen * gx[r + 1][c + 1];
                    gyGreen += image[neighborRow][neighborCol].rgbtGreen * gy[r + 1][c + 1];
                    gxRed += image[neighborRow][neighborCol].rgbtRed * gx[r + 1][c + 1];
                    gyRed += image[neighborRow][neighborCol].rgbtRed * gy[r + 1][c + 1];
                }
            }

            // Calculate the magnitude of the gradients
            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            // Ensure the values are within the valid range [0, 255]
            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }

    // Copy the edge-detected image back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
