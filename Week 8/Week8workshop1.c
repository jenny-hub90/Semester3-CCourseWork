#include <stdio.h>
#include "lodepng.h"
#include <sttdlib.h>

void main(){
	unsigned char* Image;
	unsigned int error;
	unsigned int width,height;
	lodepng_decode32_file(&Image,&width,&height,"earth.png");
	char r,g,b,t;
	unsigned char Neg[width*height*4];
	int i;
	for(i=0;i<height*width*4;i=i+4){
		r=Image[i];
		g=Image[i+1];
		b=Image[i+2];
		t=Image[i+3];
		Neg[i]=255-r;
		Neg[i+1]=255-g;
		Neg[i+2]=255-b;
		Neg[i+3]=t;
	}
	lodepng_encode32_file("negative.png",Neg,width,height);
	free(Image);
}
