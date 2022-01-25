//first 1000 numbers ko square 0-999

//1000
//2 500 500
//5 200 200 200 200 200
// 3 333 333 333
#include <stdio.h>

long long sqList[1000];

void main(int argc, char **argv){
	long long compCount = 1000;
	int threadCount = 2;
	int sliceList[threadCount];
	int remainder = compCount % threadCount;
	int i;
	
	for( i=0;i<threadCount;i++){
		sliceList[i] = compCount / threadCount;
		printf("%d",sliceList[i]);
	}
}
