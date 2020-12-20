#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
        int grayscale = round((b+g+r)/3.0);
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
    RGBTRIPLE temp;
    for(int i=0; i< height; i++)
    {
        for(int j=0; j<(width/2); j++)
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

RGBTRIPLE average_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*dup)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            dup[i][j] = average_blur(i, j, height, width, image);
            //dup[i][j].rgbtBlue = (BYTE) blur_color;
            // dup[i][j].rgbtGreen = (BYTE) blur_color;
            // dup[i][j].rgbtRed = (BYTE) blur_color;
        }
    }
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i][j] = dup[i][j];
        }
    }
    return;
}

RGBTRIPLE average_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int R =0;
    int B =0;
    int G =0;
    int counter =0;
    for(int k=-1; k<2; k++)
    {
        for(int l=-1; l<2; l++)
        {
            int m = i+k;
            int n = j+l;
            if((m>=0) && (n>=0) && (m<height) && (n<width))
            {
                int b = (int) image[m][n].rgbtBlue;
                int g = (int) image[m][n].rgbtGreen;
                int r = (int) image[m][n].rgbtRed;
                R += r;
                B += b;
                G += g;
                counter +=1;
            }
        }
    }
    RGBTRIPLE color;
    color.rgbtBlue = round((B/(counter*1.0)));
    color.rgbtGreen = round((G/(counter*1.0)));
    color.rgbtRed = round((R/(counter*1.0)));
    return color;
}