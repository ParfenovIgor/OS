#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 10
#define NULL_PTHREAD 0

pthread_t tid[N];//Array of threads' id

void* thread_do(void *arg){
	pthread_t id=pthread_self();
	int i;
	for(i=0;i<N;i++){//Try to find myself in array of threads' id
		if(pthread_equal(id,tid[i])){
			printf("Hello, I'm thread %d\n",i);
			break;
		}
	}
}

//We can notice, that outputs are shuffled. The results looks like:
//Thread 0 is created
//Thread 1 is created
//Hello, I'm thread 1
//Hello, I'm thread 0

int main(){
	int i;
	for(i=0;i<N;i++){
		pthread_create(&(tid[i]),NULL,&thread_do,NULL);//Creating new thread and saving its id into tid[i]
		printf("Thread %d is created\n",i);
	}
	sleep(1);//Wait enough time, until threads finish their work. Otherwise, some of them will be killed before they finish their work.
	return 0;
}
