#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lodepng.h"


void blur(int height, int width, image[height][width])
{
    int n;
    int m;
    int averageRed;
    int averageBlue;
    int averageGreen;

    //For each row..
    for (int i = 0; i < height; i++)
    {
        //..and then for each pixel in that row...
        for (int j = 0; j < width; j++)
        {

            //...if i and j equal 0...         
            if (i == 0 && j == 0)
            {
                for (m = i; m <= 1; m++)
                {
                    for (n = j; n <= 1; n++)
                    {
                        averageRed = averageRed + image[m][n].rgbtRed;
                        averageBlue = averageBlue + image[m][n].rgbtBlue;
                        averageGreen = averageGreen + image[m][n].rgbtGreen;

                        printf("%i\n", averageRed);
                        printf("%i\n", averageBlue);
                        printf("%i\n", averageGreen); 
                    }
                }

                image[i][j].rgbtRed = round((float)averageRed / 4);
                image[i][j].rgbtBlue = round((float)averageBlue / 4);
                image[i][j].rgbtGreen = round((float)averageGreen / 4);

                printf("%i\n", image[i][j].rgbtRed);
                printf("%i\n", image[i][j].rgbtBlue);
                printf("%i\n", image[i][j].rgbtGreen);
            }


            //If i equals 0 and j is greater than 0...
            else if (i == 0 && j > 0)
            {
                //..take the line that equals i..
                for (m = i; m <= 1; m++)
                {
                    //..and take from each pixel ot that line...
                    for (n = j - 1; n <= 1; n++)
                    {
                        //..the color values and add them to the average-variables
                        averageRed = averageRed + image[m][n].rgbtRed;
                        averageBlue = averageBlue + image[m][n].rgbtBlue;
                        averageGreen = averageGreen + image[m][n].rgbtGreen;
                    }
                }

                //Set the current pixel values to the averages
                image[i][j].rgbtRed = round((float)averageRed / 6);
                image[i][j].rgbtBlue = round((float)averageBlue / 6);
                image[i][j].rgbtGreen = round((float)averageGreen / 6);

                printf("%i\n", image[i][j].rgbtRed);
                printf("%i\n", image[i][j].rgbtBlue);
                printf("%i\n", image[i][j].rgbtGreen);
            }


            else if (i > 0 && j == 0)
            {
                for (m = i - 1; m <= 1; m++)
                {
                    for (n = j; n <= 1; n++)
                    {
                        averageRed = averageRed + image[m][n].rgbtRed;
                        averageBlue = averageBlue + image[m][n].rgbtBlue;
                        averageGreen = averageGreen + image[m][n].rgbtGreen;
                    }
                }

                image[i][j].rgbtRed = round((float)averageRed / 6);
                image[i][j].rgbtBlue = round((float)averageBlue / 6);
                image[i][j].rgbtGreen = round((float)averageGreen / 6);
            }


            else if (i > 0 && j > 0 )
            {

                // ..take every line from i - 1 to i + 1...
                for (m = i - 1; m <= 1; m++)
                {

                    //...and in each line take every pixel from j - 1 to j + 1...
                    for (n = j - 1; n <= 1; n++)
                    {

                        //...and add the RGB value to average-variables
                        averageRed = averageRed + image[m][n].rgbtRed;
                        averageBlue = averageBlue + image[m][n].rgbtBlue;
                        averageGreen = averageGreen + image[m][n].rgbtGreen;
                    }
                }

                //Set current value to the rounded average
                image[i][j].rgbtRed = ((float)averageRed / 9);
                image[i][j].rgbtBlue = ((float)averageBlue / 9);
                image[i][j].rgbtGreen = ((float)averageGreen / 9);
            }  


        }

    }
    return;

}
