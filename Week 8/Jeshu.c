#include<stdio.h>  //importing all the necessary header files
#include<stdlib.h>
#include<math.h>
void main(){
	FILE *fpointer;
	int n=91,X,Y,u,x; //declaring variables 
	printf("Enter a number:");
	//user input for x
	scanf("%d",&u);
	int sum_x,sum_y,sum_xy,sum_sqrtx,sum_sqrty,a,b,denominator;//declaring variables for the linear regression formula
	sum_x=0;//initialzing all the sum to 0
	sum_y=0;
	sum_xy=0;
	sum_sqrtx=0;
	sum_sqrty=0;
	fpointer = fopen("datasetLR2.txt","r");//reads the file
	if(fpointer==NULL){//checks whether the file is null or not
		printf("Unable to open file.\n");
		printf("Please check whether the file exists or no\n");
		exit(1);//terminates the program if the file is found null
	}
	while(fscanf(fpointer,"%d,%d\n",&X,&Y)!=EOF){//it executes the file data and manipulates it as well
		//calculating all the summation for the calculation 
		sum_x+=X;
		sum_y+=Y;
		sum_xy+=X*Y;
		sum_sqrtx+=pow(X,2);
		sum_sqrty+=pow(Y,2);
		//denominator for A and B 
		denominator = n*sum_sqrtx-pow(sum_x,2);
		//calculation of A and B
		a = sum_y*sum_sqrtx-sum_x*sum_xy/denominator;
		b = n*sum_xy-(sum_x*sum_y)/denominator;
		//calculation of x
		x = a*u+b;
		
		
		//printf("%d,%d,\t%d,%d,%d,%d,%d,%d,%d\n",X,Y,sum_x,sum_y,sum_xy,sum_sqrtx,sum_sqrty,a,b);//just to check whether the calculation is fine
		//displays the linear regrssion line y=mx+b and the value of y
		printf("y = %dx + %d,\t y = %d\n",a,b,x);
		
	}
	fclose(fpointer);
}
