#include <stdio.h>

void main(){
	
	int i, j, k, l;
	int height = 5;
	int width = 5;
	
	for(i=0; i<height; i++){
		for(j=0; j<width; j++){
				printf("(%d, %d) = ", i, j);
				for(k=-1; k<=1; k++){
					for(l=-1; l<=1; l++){
						int x = i+k;
						int y = j+l;
						if(x >= 0 && y>= 0 && y<width && x<height){
							printf("(%d %d)  ", x, y);
						}
					}
				}
			printf("\n");	
		}
		
	}
	
}
	
	

