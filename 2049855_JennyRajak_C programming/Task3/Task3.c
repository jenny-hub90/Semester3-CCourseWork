	//importing all the header file
	#include<stdio.h>
	#include<stdlib.h>
	#include<pthread.h>
	
	//declaring global variables
	int totPrimeNumbers=0;
	FILE *fptrPrimeNumbers;
	
	//declaring struct for slicing
	struct PrimeNumber{
		int begin;
		int end;
		int *array;
	};
	 
	//creating thread funtion PrimeNumber
	void* PrimeNumber(void* pointer){
	    struct PrimeNumber *limit_pointer = pointer;//void pointer type cast
	    int beginlimit = limit_pointer->begin;
	    int endlimit = limit_pointer->end;
	    int *numberofArray = limit_pointer->array;
	    
	    
	    int a,b;
	    //loop for selecting prime numbers form each of the files
	    for(a=beginlimit;a<=endlimit;a++){
	    	for(b=2;b<=numberofArray[a]-1;b++){
	    		if(numberofArray[a]%b==0){//for the non prime number if the remainder is zero it breaks the loop
	    		//printf("\n:PrimeNUmbers-> %d\n",numberofArray[a]);
	    		break;
				}
			}
			if(b == numberofArray[a]){//for storing the prime number values
				fprintf(fptrPrimeNumbers, "%d\n",numberofArray[a]);
				totPrimeNumbers++;//counts the number of prime numbers taken from each of the file
			}
		}
	}
	    
	void main(){
		//declaring variables
		int c, threads, count=0, MallocCount=0;
		//file pointer
		FILE *fptr;
		//taking user input for number of threads
		printf("Enter the number of the threads:");
		scanf("%d",&threads);
		//opening a file to add to store primenumber from each file using append so that the values does not overlap one another
		fptrPrimeNumbers = fopen("PrimeNumbers.txt","a");
		//opening the files and reading them
		//to count the number of values in each of the files
		fptr = fopen ("primeData1.txt","r");
		while(fscanf(fptr,"%d",&c)!=EOF){
			count++;
		}
		fptr = fopen ("primeData2.txt","r");
		while(fscanf(fptr,"%d",&c)!=EOF){
			count++;
		}
		fptr = fopen ("primeData3.txt","r");
		while(fscanf(fptr,"%d",&c)!=EOF){
			count++;
		}
		
		printf("\n Total number of the values: %d\n", count);
		
		//dynamically allocated memory
		int *limit = malloc(count*sizeof(int));
		//MalloccCount is used for counting the number of values from the files to make sure memory is allocated accordingly so that there is no shortage
		//dynamically memory is used to give the exact space required to store the number of prime numbers
		fptr = fopen("primeData1.txt","r");
		while(fscanf(fptr, "%d", &limit[MallocCount])!=EOF){
			MallocCount++;
		}
		fptr = fopen("primeData2.txt","r");
		while(fscanf(fptr, "%d", &limit[MallocCount])!=EOF){
			MallocCount++;
		}
		fptr = fopen("primeData3.txt","r");
		while(fscanf(fptr, "%d", &limit[MallocCount])!=EOF){
			MallocCount++;
		}
		
		//Slicing for no of threads
		int sliceListing[threads];
		int extra = count % threads;
		//it makes sure that no data is left to be printed out
		int a;
		for(a=0;a<threads;a++){
			sliceListing[a] = count / threads;//slicing the number of threads the user has inputs
		}
		//for the extra values to be printed out
		for(a=0;a<extra;a++){
			sliceListing[a]= sliceListing[a]+1;
		}
		int beginlist[threads];
		int endlist[threads];
		//for loop for running the number of threads one after another with proper indexing
		for(a=0;a<threads;a++){
			if(a==0){
				beginlist[a]=0;
			}else{
			    beginlist[a] = endlist[a-1]+1;
			}
			endlist[a]= beginlist[a]+sliceListing[a]-1;
		}
		//declaring the pthread
		pthread_t id[threads];
		
		//declaring the struct PrimeNumber to for the number of threads to be sliced
		struct PrimeNumber main[threads];
		
		//for loop for taking the value form the file and creating multithread
		for(a=0;a<threads;a++){
			main[a].begin = beginlist[a];
			main[a].end = endlist[a];
			main[a].array = limit;
			pthread_create(&id[a],NULL,PrimeNumber,&main[a]);
		}
		
	    //joins the threads and runs the thread one after another	
		int d;
		
		for(d=0;d<threads;d++){
			pthread_join(id[d],NULL);
			
		}
		//prints the total number of PrimeNumber that are printed in the file
		fprintf(fptrPrimeNumbers, "Total Number of prime numbers: %d",totPrimeNumbers);
		//close the file
		fclose(fptr);
		fclose(fptrPrimeNumbers);
		//releazies memory size after compiling each time
		free(limit);
		
		
	}
