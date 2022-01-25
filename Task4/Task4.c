	//importing all the necessary header file
	#include <stdio.h>
	#include <stdlib.h>
	#include "lodepng.h" 
	
	void main(){
		//declaring the variables
		int a,b,c,d;
		//declaring the size of the Kernel
		int Kernel= 10;
		unsigned error;
		unsigned char *IMAGE;
		unsigned height,width;
		char Inputfilename[1000];
		char Outputfilename[1000];
		//user input for the inputfilename
		printf("Name of the input file:");
		scanf("%s",Inputfilename);
		//user input for the ouputfilename
		printf("Please mention a output file name:");
		scanf("%s",Outputfilename);
		//decoing the original Image
		error = lodepng_decode32_file(&IMAGE,&width,&height,Inputfilename);
		//dynamic memory allocation for the height and width of the image
		int ***arg = (int***)malloc(height*sizeof(int**));
		
		for(a=0;a<height;a++){
			arg[a] = (int**)malloc(width*sizeof(int*));
			for(b=0;b<width;b++){
				arg[a][b] = (int*)malloc (3*sizeof(int));
			}
		}
		//printing the height and width of the image
		printf("height->%d,width->%d\n",width,height);
		
		if(error){
			printf("error decoding image %d: %s\n",error,lodepng_error_text(error));
		}else{
		
		for(a=0;a<height;a++){
			for(b=0;b<width;b++){
				for(c=0;c<3;c++){
					arg[a][b][c] = IMAGE[4*width*a+4*b+c];
				}
			}
		}
	}
		//for loop for taking the average for the RGB 
		for(a=0;a<height;a++){
			for(b=0;b<width;b++){
				float Redavg=0, Greenavg=0, Blueavg=0, pixel=0;
				for(c=-Kernel;c<=Kernel;c+=Kernel){
					for(d=-Kernel;d<=Kernel;d+=Kernel){
						if((a+c && b+d)>=0 && (b+d) < width && (a+c < height)){
							Redavg += arg[a+c][b+d][0];
							Greenavg += arg[a+c][b+d][1];
							Blueavg += arg[a+c][b+d][2];
							pixel++;
						}
					}
				} 
				IMAGE[4*width*a+4*b+0] = Redavg/pixel;
				IMAGE[4*width*a+4*b+1] = Greenavg/pixel;
				IMAGE[4*width*a+4*b+2] = Blueavg/pixel;
			}
		}
		//encoding the blurr image
		unsigned char *png;
		size_t pngsize;
		error = lodepng_encode32(&png,&pngsize, IMAGE, width, height);
		if(!error){
			lodepng_save_file(png, pngsize, Outputfilename);
		}
	}
	
	

