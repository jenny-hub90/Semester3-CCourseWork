#include<stdio.h>
#include "lodepng.h"
#include<stdlib.h>


void main()
{
	int i;
unsigned char* Image;
unsigned int width,height;
unsigned int error;
error=lodepng_decode32_file(&Image,&width,&height,"fourbyfour.png");
if(error)
 {
 	printf("%d %s",error,lodepng_error_text(error));
 }
printf("%d %d\n",width,height); 
 for(i=0;i<width*height*4;i=i+4)
  {
 	printf("%d %d %d %d\n",Image[i],Image[i+1],Image[i+2],Image[i+3]);
  } //Each pixels have four values: R,G,B,T.   
free(Image);

}
