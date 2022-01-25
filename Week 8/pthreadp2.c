#include <stdio.h>
#include <pthread.h>

void *mythread_function(void *args){
	printf("I am a thread by %s\n",(char*) args);
	
}
int main(){
	printf("program started\n");
	
	pthread_t t1,t2;
	pthread_create(&t1, NULL, mythread_function, "t1");
	pthread_create(&t2, NULL, mythread_function, "t2");
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("program finished.\n");
	return 0;
}
