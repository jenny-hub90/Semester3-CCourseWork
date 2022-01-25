#include<stdio.h>
#include"lodepng.h"
#include<stdlib.h>

void main(){
	unsigned char* Image;
	unsigned int error;
	unsigned int width,height;
	unsigned char r,g,b,t,gray;
	int i;
	error=lodepng_decode32_file(&Image,&width,&height,"xyz.png");
	if (error){
		printf("%d %s",error,lodepng_error_text(error));
		exit(1);
	}
	unsigned char new[width*height*4];
	for(i=0;i<width*height*4;i=i+4){
	   
		r=Image[i];
		g=Image[i+1];
		b=Image[i+2];
		t=Image[i+3];
		gray=(r+g+b)/3;
		new[i]=gray;
		new[i+1]=gray;
		new[i+2]=gray;
		new[i+3]=t;
	
}
	
lodepng_encode32_file("grayscale.png",new,width,height);
free(Image);
	
}
