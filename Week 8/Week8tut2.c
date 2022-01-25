#include <stdio.h>
#include "lodepng.h"

void main(){
	int i,j;
	unsigned error;
	unsigned char *image;
	unsigned w,h,r,g,b,a;
	char filename[1000];
	printf("Enter file name:\n");
	scanf("%s",filename);
	error= lodepng_decode32_file(&image,&w,&h,filename);
	if(error){
		printf("Error in decoding image :%s\n",error,lodepng_error_text(error));
		
	}
	for(i=0; i<h;i++){
		for(j=0;j<w;j++){
		r=image[4*w*i+4*j+0];
		g=image[4*w*i+4*j+1];
		b=image[4*w*i+4*j+2];
		a=image[4*w*i+4*j+3];
		printf("[%3d %3d %3d %3d]\t",r,g,b,a);	
		}
		printf("\n");
	}
}
