#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lodepng.h"

void get_gau_kernel(float **kernel, int size, float sigma)
{
	if (size <= 0 || sigma == 0)
		return;
 
	int x, y;
	int m = size / 2;
	float sum = 0;
 
	//get kernel
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			kernel[y][x] = (1 / (2 * PI * sigma * sigma)) * exp(-((x - m) * (x - m) + (y - m) * (y - m)) / (2 * sigma * sigma));
			sum += kernel[y][x];
		}
	}
 
	//normal
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			kernel[y][x] /= sum;
		}
	}
}
 
 
 /*Function: Gaussian Blur
 //src: input original image
 //dst: Blurred image
 //size: the size of the core
 //sigma: standard deviation of normal distribution
*/
void gaussian(image_t *src, image_t *dst, int size, float sigma)
{
	if (src->w == 0 || src->h == 0)
		return;
 
	int y, x;
	int i, j;
	int m = size / 2;
	float value;
 
	float **kernel = (float**)malloc(size * sizeof(float*));
	for (i = 0; i < size; i++)
		kernel[i] = (float*)malloc(size * sizeof(float));
 
	get_gau_kernel(kernel,size,sigma);
 
	float *kernel_vec = (float*)malloc(size * size * sizeof(float));
 
	 //kernel two-dimensional to one-dimensional
	int k = 0;
	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size; i++)
		{
			kernel_vec[k++] = kernel[j][i];
		}
	}
 
	uchar *src_ptr = src->data + m * src -> w;
	uchar *dst_ptr = dst->data + m * dst -> w;
	 //gaussian convolution, the boundary is not processed at this time
	for (y = m; y < src -> h - m ; y++)
	{
		for (x = m; x < src->w - m; x++)
		{
 
			value = 0;
			k = 0;
			for (j = -m; j < m;j++)
			{
				for (i = -m; i < m; i++)
				{
					uchar temp = src_ptr[(y + j) * src->w + (x + i)];
					float temp1 = kernel_vec[k++];
					value += temp * temp1;
				}
			}
 
			dst_ptr[x] = (uchar)(value);
		}
 
		dst_ptr += dst->w;
	}
 
	free(kernel_vec);
	for (i = 0; i < size; i++)
		free(kernel[i]);
	free(kernel);
}
