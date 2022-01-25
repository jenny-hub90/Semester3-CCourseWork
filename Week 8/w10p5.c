#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *fun(void* arg){
	int *a = malloc(sizeof(int));
	*a = 5;
	pthread_exit((void*)a);
	
}

void main(){
	void* ptr;
	pthread_t thread1;
	pthread_create(&thread1, NULL, fun, NULL);
	pthread_join(thread1,&ptr);
	printf("%d\n",*(int*)ptr);
	free(ptr);
}
