#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* first(void *p){
	while(1){
		sleep(1);
		printf("I am free first \n");
	}
}
void second(){
	while(1){
		sleep(2);
		printf("I am free second \n");
	}
}
void main(){
	pthread_t thread1;
	
	pthread_create(&thread1,NULL,first,NULL);
	second();
}
