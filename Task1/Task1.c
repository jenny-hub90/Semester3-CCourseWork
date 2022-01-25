	//importing the necessary header files
	#include <stdio.h>
	#include <stdlib.h>
	
	void main()
	{
		//open four files to be merged
		FILE* fptr1 = fopen ("datasetLR1.txt","r");
		FILE* fptr2 = fopen ("datasetLR2.txt","r");
		FILE* fptr3 = fopen ("datasetLR3.txt","r");
		FILE* fptr4 = fopen ("datasetLR4.txt","r");
		
		//open file to store all the merged file
		FILE* fptr5 = fopen ("datasetLR5.txt","w");
		char b;
		
		if(fptr1 == NULL || fptr2 == NULL || fptr3 == NULL || fptr4 == NULL || fptr5 == NULL){
			puts("Error opening the file");
			exit(0);
		}
		
		//copying content of the first file to datasetLR5.txt
		while((b = fgetc(fptr1))!=EOF){
		fputc(b,fptr5);
	}
		
		//copying content of the second file to datasetLR5.txt
		while((b = fgetc(fptr2))!=EOF){
		fputc(b,fptr5);
	}
		
		
		//copying content of the third file to datasetLR5.txt
		while((b = fgetc(fptr3))!=EOF){
		fputc(b,fptr5);
	}
		
		
		//copying content of the fourth file to datasetLR5.txt
		while((b = fgetc(fptr4))!=EOF){
		fputc(b,fptr5);
	}
	    
		printf("Your files have been successfully merged into datasetLR5.txt\n");
		//closing all the opened files
		fclose(fptr1);
		fclose(fptr2);
		fclose(fptr3);
		fclose(fptr4);
		fclose(fptr5);
		//initializing all the variables needed for the formula
		int n=406,x,y;
		float sumx=0, sumy=0, sumx2=0,sumxy=0,A,a,B,X;
		//making user input for x
		printf("Enter a number:");
		scanf("%f",&a);
		fptr5 = fopen ("datasetLR5.txt","r");//reading the merged data
		fscanf(fptr5,"%d,%d",&x,&y);
		while(!feof(fptr5)){
			fscanf(fptr5,"%d,%d\n",&x,&y);//displaying all the x and y value in the file
			//printf("%d,%d\n",x,y);
			//Calculating required sum
			sumx=sumx+x;
			sumy=sumy+y;
			sumx2=sumx2+(x*x);
			sumxy=sumxy+(x*y);
			//calculation of A and B by applying linear regression formula
			B = (n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
			A = (sumy - B*sumx)/n;
			//calculating x so that we get the value of y
			//using formula y=bx+a
			X= B*a+A;
			//To display value od A and B printf("values of A and B are A:%0.2f and B:%0.2f");
		
			}
			//printing them
			//Using formula y=mx+c
		printf("\nEquation of best fit is: Y=   %0.2f+ %0.2fx , Y = %0.2f\n",A,B,X);
	    //closing the file  	
	    fclose(fptr5);
	    
	}

