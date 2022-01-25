#include <stdio.h>
#include <pthread.h>

int ch = 5;
void* fun(void* arg){
	ch = 5;
	pthread_exit((void*)&ch);
}
void main(){
	void *ptr;
	pthread_t thread1;
	pthread_create(&thread1, NULL, fun, NULL);
	pthread_join(thread1,&ptr);
	printf("%d\n",*(int*)ptr);
}
