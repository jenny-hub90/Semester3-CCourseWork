#include<stdio.h>
#include<pthread.h>
int sum1=0;
void * fun1(void *arg){
	int i,start=1,finish=1000;
	for(i=start;i<=finish;i++){
		sum1= sum1+i;
	}
	pthread_exit((void*)&sum1);
}

void main(){
	void *s1;
	pthread_t thread1;
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_join(thread1,&s1);
	printf("%d\n",*(int*)s1);
}
