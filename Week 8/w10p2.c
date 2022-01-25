#include <stdio.h>
#include <pthread.h>

void* fun(void* arg){
	int i,start=1,finish=500;
	for(i=start;i<=finish;i++){
		printf("Thread one and i=%d\n",i);
	}
}

void* fun2(void* arg){
	int i,start=501,finish=1000;
	for(i=start;i<=finish;i++){
		printf("Thread two and i=%d\n",i);
	}
}

void main(){
	pthread_t thread1,thread2;//creating thread id
	pthread_create (&thread1, NULL, fun ,NULL);
	pthread_create (&thread2, NULL, fun2 , NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
}
