#include <stdio.h>
#include "lodepng.h"

void main(){
	int i;
	unsigned error;
	unsigned char *image;
	unsigned w,h;
	char filename[1000];
	printf("Enter file name:\n");
	scanf("%s",filename);
	error= lodepng_decode32_file(&image,&w,&h,filename);
	if(error){
		printf("Error in decoding image :%s\n",error,lodepng_error_text(error));
		
	}
	for(i=0;i<w*h;i++){
		printf("%3d %3d %3d %3d\n",image[i*4+0],image[i*4+1],image[i*4+2],image[i*4+3]);
	}
}
