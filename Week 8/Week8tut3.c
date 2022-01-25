#include <stdio.h>
#include "lodepng.h"

void main(){
	int i,j;
	unsigned error;
	unsigned char *image;
	unsigned w,h,r,g,b,a;
	char filename[1000] ;
	char outfilename[1000];
	printf("Enter a input file name:\n");
	scanf("%s",filename);
	printf("Enter a output file name:\n");
	scanf("%s",outfilename);
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
		b=255;
		image[4*w*i+4*j+2]=b;
		printf("[%3d %3d %3d %3d]\t",r,g,b,a);	
		}
		printf("\n");
	}
	unsigned char *png;
	size_t pngsize;
	error= lodepng_encode32(&png, &pngsize, image, w,h);
	if(!error){
		lodepng_save_file(png,pngsize,outfilename);
	}
}
