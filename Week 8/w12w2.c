#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int counter = 0;
sem_t semaphore;
void *threadOne(void *p)

{
int i;
int temp;
for(i=1; i<=3; i++)
{
sem_wait (&semaphore);
temp = counter;
sleep(1);
counter = temp +1;
sem_post(&semaphore);
}
}
void *threadTwo(void *p)
{
int i;
int temp;
for (i=1; i<=3; i++)
{
sem_wait (&semaphore);
temp = counter;
sleep(1);
counter = temp - 1;
sem_post(&semaphore);
}
}
void main()
{
sem_init(&semaphore,0,1);
pthread_t thrID1, thrID2;
pthread_create(&thrID1, NULL, threadOne, NULL);
pthread_create(&thrID2, NULL, threadTwo, NULL);
pthread_join(thrID1, NULL);
pthread_join(thrID2, NULL);
printf("counter = %d\n", counter);
sem_destroy(&semaphore);
}
