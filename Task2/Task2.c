	//importing the header files
	#include <stdio.h>
	#include <windows.h>
	#include <pthread.h>
	#include <math.h>
	#include <unistd.h>
	#include <semaphore.h>
	
	
	//declaring global variable
	float pi =0;
	//declaration of semaphore variable
	sem_t semaphore;
	//initalization of strcut for Slicing
	struct Leibiniz{
		int start;
		int finish;
		
	};
	
	//creating thread function
	void* function(void* pointer){
		sem_wait(&semaphore);
		//the program sleeps for 2 sec and waits to run the thread one after another displaying the value of the PI
	    sleep(2);
	    struct Leibiniz *ar =(struct Leibiniz*)pointer;
	    int start = ar->start;
	    int finish = ar->finish,i;
	    int addup;
	    pthread_t a = pthread_self();
	    //Implementing Leibiniz formula for the finding the value of PI
	    for(addup=start;addup<=finish;addup++){
	    	//for loop for running Slicing of threads
	        double sum = 0;
	        int n;
	        for(n=0;n<=addup;n++){
	        sum = sum + pow(-1,n)/(2*n+1);
	        }
	        pi = sum * 4;
	        //printing the value of PI
	        printf("%d->%.2lf\n",addup,pi);
	    }
	    
	    sem_post(&semaphore);
	}
	
	void main(){
		//declaring the variables
		int iteration,threads;
		//taking user inputs for no of iteration and threads
		printf("Enter the number of iterations:");
		scanf("%d",&iteration);
		printf("Enter the number of threads: ");
		scanf("%d",&threads);
		pthread_t b[threads];
	    sem_init(&semaphore,0,1);
	    struct Leibiniz c[threads];
	    int sliceList[threads];
	    int i;
	    //Equally slicing among the number of threads
	    for(i=0;i<threads;i++){
	        sliceList[i]=iteration/threads;
	    }
	    //if the iteration is unequally divided remainder makes sure that the remaining number are added to the threads as well
	    int remainder = iteration%threads;
	    for(i=0;i<remainder;i++){
	        sliceList[i]=sliceList[i]+1;
	    }
	    //for loop for running the number of threads one after another with proper indexing
	    for(i=0;i<threads;i++){
	        if(i==0){
	            c[i].start =1;
	        }else{
	            c[i].start=c[i-1].finish+1;
	        }
	    c[i].finish=c[i].start+sliceList[i]-1;
	    
	}
	//creating number of threads
	for(i=0;i<threads;i++){
	    pthread_create(&b[i],NULL,function,&c[i]);
	}
	//joining the number of threads and runs the threads one after another
	for(i=0;i<threads;i++){
	    pthread_join(b[i],NULL);
	    }
	//destroying semaphore 
	sem_destroy(&semaphore);
	
	}

