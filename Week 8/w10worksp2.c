#include<stdio.h>
#include<pthread.h>
#define numofthreads 5

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
void main()
{
	int numofthreads;
	scanf("%d",&numofthreads);
	pthread_t id[numofthreads];
	struct abc s[numofthreads] ;
	int slicelist[numofthreads],i;
	for(i=0;i<numofthreads;i++)
	{
	  slicelist[i]=1000/numofthreads;
	}
	int remainder=1000%numofthreads;
	for(i=0;i<remainder;i++)
	{
		slicelist[i]=slicelist[i]+1;
	}
for(i=0;i<numofthreads;i++)
{
	printf("%d\n",slicelist[i]);
}
for(i=0;i<numofthreads;i++){
       if(i==0)
         {
         s[i].start=1;
         }
       else{
                
