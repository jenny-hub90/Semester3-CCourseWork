#include <stdio.h>
#include <pthread.h>

void* fun(void* arg){
	int i,start=1,finish=1000;
	for(i=start;i<=finish;i++){
		printf("Thread one and i=%d\n",i);
	}
}





void main(){
	pthread_t thread1;//creating thread id
	//creating thread
	pthread_create(&thread1,NULL/*making sure not to change the default value of the thread*/,fun/*creating thread function*/,NULL);
	pthread_join(thread1,NULL);
}
