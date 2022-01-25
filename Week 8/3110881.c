#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
int *file;
int count =0;
FILE * file1;
sem_t semaphore;
struct prog{
	int start;
	int end;
	int array[];
};
int checkprog(int n){
int j;
	
 	for(j=2;j<=n/2;j++){
 		if(n%j == 0){
 			return 0;
		 }
	 }
	
	return 1;
}
void *find_prog(void * args){
	file1 = fopen("ans.txt","w");
	int j,start,end;
	
	struct prog *s = (struct prog*) args;
	start = s->start;
	end = s->end;
	
	for(j=start;j<=end;j++){
		int check = checkprog(file[j]);
	       sem_wait(&semaphore);  
	 if(check ==1){
	 	
			count++;
			
				fprintf(file1,"%d\n",file[j]);
		}
		sem_post(&semaphore);
	}
}
void main(){
printf("Ruk jao jara ruko jara...");
	int len;
		int j=0,x_y;

	FILE *file1,*file2,*file3;
	
	file1= fopen("PrimeData1.txt","r");
	
	file2= fopen("PrimeData2.txt","r");

	file3= fopen("PrimeData3.txt","r");


	while(fscanf(file1,"%d",&x_y) != EOF){	
	j++;
}
while(fscanf(file2,"%d",&x_y) != EOF){	
	j++;
}
while(fscanf(file3,"%d",&x_y) != EOF){	
	j++;
}
len = j;
	
	sem_init(&semaphore,0,1);
	int threadCount;
	printf("\nenter the number of threads : ");
	scanf("%d",&threadCount);
	file = (int*) malloc(len * sizeof(int));
 	

	j=0;
	
		file1= fopen("PrimeData1.txt","r");
	while(fscanf(file1,"%d",&file[j]) != EOF){

	j++;
}
	file2= fopen("PrimeData2.txt","r");
	while(fscanf(file2,"%d",&file[j]) != EOF){

	j++;
}
	file3= fopen("PrimeData3.txt","r");
	while(fscanf(file3,"%d",&file[j]) != EOF){

	j++;
}
fclose(file1);
fclose(file2);
fclose(file3);

	
int remainder = len%threadCount;

int sliceList[threadCount];
 
 for(j=0;j<threadCount;j++){
	sliceList[j] =len / threadCount;
}
for(j=0;j<remainder;j++){
	sliceList[j] = sliceList[j] + 1;
}
for(j=0;j<threadCount;j++){

}

int startList[threadCount];
int endList[threadCount];

for(j = 0;j<threadCount;j+=1){
	int a = j;
	if(j==0){
		startList[j] =0;
		
	}
	else{
		startList[j] = endList[a-1]+1;
	}
	 endList[j] = startList[j] + sliceList[j]-1;

}

struct prog points[threadCount];

for(j = 0;j<threadCount;j++){
 	points[j].start = startList[j];
 	points[j].end = endList[j];
 }

pthread_t threads[threadCount];

for(j=0;j<threadCount;j++){
	pthread_create(&threads[j],NULL,find_prog,&points[j]);
	
}
for(j=0;j<threadCount;j++){
	pthread_join(threads[j],NULL);
}
fprintf(file1,"Total %d \n",count);

printf("\nsaved to file1 successfully \ntotal prime numbers found : %d",count);

free(file);
fclose(file1);
sem_destroy(&semaphore);
}


