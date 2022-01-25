#include <stdio.h>
#inlcude <pthread.h>

sem_t semaphore;

void *threadFunc(void *p){
	sem_wait(&semaphore);
	sleep(2);
	printf("Hello from the thread %d\n",*(int *)p);
	sem_post(&semaphore);
	
	
}


void main(){
	pthread_t th[4]
	int a[4]={1,2,3,4};
	int i;
	for(i=0;i<4;i++){
		pthread_create  (&th[i], NULL, threadFunc, &a[i]);
		}
		
	for(i=0; i<4;i++)
{
	pthread_join(th[i],NULL);
}
sem_destroy(&semaphore);

}
