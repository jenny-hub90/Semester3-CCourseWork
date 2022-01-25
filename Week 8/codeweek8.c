#include<stdio.h>
#include<stdlib.h>
#include "lodepng.h"
void main(){
unsigned char *image;
unsigned error,err;
unsigned w,h;

error = lodepng_decode32_file(&image,&w,&h,"xyz.png");

if(error){
	printf("%s",lodepng_error_text(error));
}
	int i;
	int avg;
	
		for(i=0;i<w*h*4;i+=4) 
{
	avg = (image[i] + image[i+1] + image[i+2])/3;
	    image[i] = avg;
		image[i+1]=avg;
		image[i+2]=avg;
}
unsigned char *copy = image;
	
 err =lodepng_encode32_file("result.png",copy,w,h);
	free(image);
	
}
