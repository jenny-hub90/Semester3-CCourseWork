#include <stdio.h>
#include <pthread.h>
struct abc{
int start;
int finish;
};

void* fun(void* ptr){
	struct abc *arg=(struct abc*)ptr;
	int st=arg->start;
	int fi=arg->finish,i;
	pthread_t tid= pthread_self();
	for(i=st;i<=fi;i++){
	printf("Thread %d and i=%d\n",tid,i);
	sleep(1);
	}
	}
void main(){
	pthread_t thread1,thread2;
	//creating thread id
	struct abc s1,s2;
	s1.start=1;
	s1.finish=500;
	s2.start=501;
	s2.finish=1000;
	pthread_create (&thread1, NULL, fun ,&s1);
	pthread_create (&thread2, NULL, fun ,&s2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
}
