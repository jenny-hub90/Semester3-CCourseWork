#include <stdio.h>
#include <stdlib.h>

long long sqList[1000];

void main(int argc, char **argv){
	long long compCount = 1000;
	int threadCount = atoi(argv[1]);
	int sliceList[threadCount];
	int remainder = compCount % threadCount;
	int i,j;
	
	for( i=0;i<threadCount;i++){
		sliceList[i] = compCount / threadCount;
	}
	
	for(j=0; j<threadCount;j++){
		sliceList[j] = sliceList[j]+1;
	}
	
	for(i=0; i<threadCount;i++){
		printf("%d\n",sliceList[i]);
	}
	printf("rem= %d\n",remainder);
}
