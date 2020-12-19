#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
for(int i=0; i< height; i++)
{
    for(int j=0; j< width; j++)
    {
        int b = (int) image[i][j].rgbtBlue;
        int g = (int) image[i][j].rgbtGreen;
        int r = (int) image[i][j].rgbtRed;
        int grayscale = (b+g+r)/3;
        image[i][j].rgbtBlue = (BYTE) grayscale;
        image[i][j].rgbtGreen = (BYTE) grayscale;
        image[i][j].rgbtRed = (BYTE) grayscale;
    }
}
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int b = (int) image[i][j].rgbtBlue;
            int g = (int) image[i][j].rgbtGreen;
            int r = (int) image[i][j].rgbtRed;

            int sepiaRed = round((.393 * r) + (.769 * g) + (.189 * b));
            int sepiaGreen = round((.349 * r) + (.686 * g) + (.168 * b));
            int sepiaBlue = round((.272 * r) + (.534 * g) + (.131 * b));

            if(sepiaBlue>=255)
                sepiaBlue = 255;
            if (sepiaGreen>=255)
                sepiaGreen = 255;
            if (sepiaRed>=255)
                sepiaRed = 255;

            image[i][j].rgbtBlue = (BYTE) sepiaBlue;
            image[i][j].rgbtGreen = (BYTE) sepiaGreen;
            image[i][j].rgbtRed = (BYTE) sepiaRed;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{   int counter = width;
    int midpoint = round((width/2) - 0.5);
    RGBTRIPLE temp;
    for(int i=0; i< height; i++)
    {
        for(int j=0; j<=midpoint; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][counter-1];
            image[i][counter-1] = temp;
            counter = counter-1;
        }
        counter = width;
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    return;
}
