#include<stdio.h>
#include "lodepng.h"
#include<stdlib.h>
void main()
{
int i;
unsigned	char* Image;
unsigned	int width,height;
unsigned int error;
error=lodepng_decode32_file(&Image,&width,&height,"xyz.png");
  if(error)
	{
	printf("%d %s",error,lodepng_error_text(error));
	}
printf("%d %d\n",width,height);    
for(i=0;i<width*height*4;i++) 
{
	if(Image[i]<200)
	{
		Image[i]=Image[i]+50;
	}
	
 }
    lodepng_encode32_file("wow.png",Image,width,height);
   free(Image); 

 
 
 
 



}
