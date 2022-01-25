#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int count=0;
sem_t semaphore;
void* fun(void* arg)
{
sem_wait (&semaphore);
count++;
int i;
printf("Thread %d has started\n",count);
for(i=1;i<=1000000;i++){ }
printf("Thread %d has finished\n",count);
sem_post(&semaphore);
}
void main()
{
sem_init(&semaphore,0,1);
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,fun,NULL);
pthread_create(&thread2,NULL,fun,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
sem_destroy(&semaphore);
}
