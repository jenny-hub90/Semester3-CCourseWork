#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main() {
	FILE *apointer;
	int x,y,i,x_sum,y_sum,xny_sum,xsq_sum,ysq_sum,A,B,multiply,divide,n=90;
    x_sum = 0;
    y_sum = 0;
    xny_sum = 0;
    xsq_sum = 0;
    ysq_sum = 0;
    apointer = fopen("datasetLR2.txt","r");
    if (apointer== NULL) {
        printf("Error! opening file");
        exit(1);
    }
    while(fscanf(apointer,"%d,%d\n",&x,&y)!=EOF){
    x_sum = x_sum+x;
    y_sum = y_sum+y;
    multiply = x*y;
	xny_sum = multiply+ xny_sum;
	xsq_sum = xsq_sum + pow(x,2);
	ysq_sum = ysq_sum + pow(y,2);
	divide = n*xsq_sum-pow(x_sum,2);
	A = y_sum*xsq_sum-x_sum*xny_sum/divide;
	B = n*xny_sum-x_sum- x_sum*y_sum/divide;
	printf(" %d,%d, \t %d ",x,y,x_sum);
   }
    
    fclose(apointer);

}
