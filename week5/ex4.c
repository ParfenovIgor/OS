#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_N 1000
#define MAX_NUMBER_OF_THREADS 100
#define NULL_PTHREAD 0

//The main idea of this solution is associativity of least common multiplier fuction:
//lcm(a,b,c)=lcm(a,lcm(b,c))
//Scheme of algorithm:
// x_0   ..   x_(len-1) | x_len   ..   x_(2*len-1) | .. | x_((k-1)*len) .. x_(n-1)
// thread1                thread2                         thread k
// lcm(x_0, .. ,x_(len-1) lcm(x_len .. x_(2*len-1)        lcm(x_((k-1)*len) .. x_(n-1)
// lcm(x_0, .. x_(n-1))

int N,number_of_threads;//Number of numbers in input file and number of threads used to calculate lcm
pthread_t tid[MAX_NUMBER_OF_THREADS];//Threads' id
int left[MAX_NUMBER_OF_THREADS],right[MAX_NUMBER_OF_THREADS];//Segments of array, which have to compute thread
int result[MAX_NUMBER_OF_THREADS];//Result lcm of every thread
int numbers[MAX_N];//Input array

//Function to computer greatest common divisor
int gcd(int a,int b){
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}

//Function to compute least common multiplier
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

void* thread_do(void *arg){
	pthread_t id=pthread_self();
	int my_id,i;
	for(i=0;i<N;i++){//Find myself in list to get id
		if(pthread_equal(id,tid[i])){
			my_id=i;
			break;
		}
	}
	//Compute lcm in my segment
	int res=numbers[left[my_id]];
	for(i=left[my_id]+1;i<=right[my_id];i++)
		res=lcm(res,numbers[i]);
	//Place result in global table
	result[my_id]=res;
}

int main(int argc,char* argv[]){
	if(argc<3){
		printf("Expected input file and number of threads\n");
		return 0;
	}

	number_of_threads=atoi(argv[2]);
	FILE *file=fopen(argv[1],"r");	
	int i=0;
	while(fscanf(file,"%d",&numbers[i])!=-1){
		i++;
	};
	fclose(file);
	N=i;

	int len;//Len of segments for all threads except probably the last one
	if(number_of_threads>N)
		number_of_threads=N;
	if(N%number_of_threads==0)
		len=N/number_of_threads;
	else
		len=N/number_of_threads+1;
	for(i=0;i<number_of_threads;i++){
		left[i]=i*len;
		right[i]=(i+1)*len-1;
	}
	right[number_of_threads-1]=N-1;//Crop last segments if the number of elements in input array is not divisible by number of threads

	for(i=0;i<number_of_threads;i++){//Start threads
		pthread_create(&(tid[i]),NULL,&thread_do,NULL);
	}
	for(i=0;i<number_of_threads;i++){//Wait, until all threads finish their work
		pthread_join(tid[i],NULL);
	}

	//Compute the total lcm, using result of threads
	int res=result[0];
	for(i=1;i<number_of_threads;i++)
		res=lcm(res,result[i]);

	printf("%d\n",res);
	return 0;
}
