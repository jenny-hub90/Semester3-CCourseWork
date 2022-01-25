#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* fun(void * arg){
	int i;
	for(i=1;i<=100000;i++){
		printf("Hello and i=%d\n",i);
	}
}

void main(){
	pthread_t thread1;
	pthread_create(&thread1 ,NULL, fun, NULL);
	sleep(1);
	pthread_cancel(thread1);
	pthread_join(thread1,NULL);
}
