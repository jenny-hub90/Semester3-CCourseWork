#include<stdio.h>
#include<pthread.h>
int sum1=0;
void * fun1(void *arg){
	int i,start=1,finish=500;
	for(i=start;i<=finish;i++){
		sum1= sum1+i;
	}
	pthread_exit((void*)&sum1);
}

int sum2=125250;
void * fun2(void *arg){
	int i,start=501, finish=1000;
	for(i=start;i<=finish;i++){
		sum2= sum2+i;
	}
	pthread_exit((void*)&sum2);
}

void main(){
	void *s1,*s2;
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1,&s1);
	pthread_join(thread2,&s2);
	printf("%d\n",*(int*)s1);
	printf("%d\n",*(int*)s2);
}
