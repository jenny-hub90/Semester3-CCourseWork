#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<math.h>

double pi = 0;

pthread_mutex_t mutex;

struct leib{
    int start;
    int finish;
};

void* func(void* ptr){
    pthread_mutex_lock(&mutex);
    struct leib *ar =(struct leib*)ptr;
    int st = ar->start;
    int fi = ar->finish,i;
    int count;
    pthread_t tid = pthread_self();
    
    for(count=st;count<=fi;count++){
        double sum = 0;
        int n;
        for(n=0;n<=count;n++){
        sum = sum + pow(-1,n)/(2*n+1);
        }
        pi = sum * 4;
        printf("%d:%.2lf\n",count,pi);
    }
    
    
    pthread_mutex_unlock(&mutex);
}

void main(){
    int numofthreads,iterations;
    printf("Enter number of iterations:");
    scanf("%d",&iterations);
    printf("Enter the number of threads:");
    scanf("%d",&numofthreads);

    pthread_t ids[numofthreads];
    pthread_mutex_init(&mutex,NULL);
    struct leib p[numofthreads];
    int sliceList[numofthreads],i;
    for(i=0;i<numofthreads;i++){
        sliceList[i]=iterations/numofthreads;
    }
    int remainder = iterations%numofthreads;
    for(i=0;i<remainder;i++){
        sliceList[i]=sliceList[i]+1;
    }

    for(i=0;i<numofthreads;i++){
        if(i==0){
            p[i].start =1;
        }else{
            p[i].start=p[i-1].finish+1;
        }
    p[i].finish=p[i].start+sliceList[i]-1;
    
}

for(i=0;i<numofthreads;i++){
    pthread_create(&ids[i],NULL,func,&p[i]);
}
for(i=0;i<numofthreads;i++){
    pthread_join(ids[i],NULL);
}


}