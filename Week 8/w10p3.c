#include <stdio.h>
#include <pthread.h>
char ch ='A';
void* fun(void* arg){
	//printf("%c\n",ch);
	pthread_exit((void*)&ch);
}

void main(){
	void* ptr;
	pthread_t thread1;
	pthread_create(&thread1,NULL,fun,NULL);
	pthread_join(thread1,&ptr);
	printf("%c\n",*(char*)ptr);
}
