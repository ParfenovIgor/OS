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

int main(){
	int i;
	for(i=0;i<N;i++){
		pthread_create(&(tid[i]),NULL,&thread_do,NULL);//Creating new thread and saving its id into tid[i]
		printf("Thread %d is created\n",i);
		pthread_join(tid[i],NULL);//Wait until i-th thread finish execution. If we remove this line, threads' outputs will be shuffled.
		tid[i]=NULL_PTHREAD;//If we won't do this, then next thread will most possibly get id equal to id of previous thread, and all threads will recognize themselves as 0-th thread.
	}
	sleep(1);//Wait enough time, until threads finish their work. Otherwise, some of them will be killed before they finish their work. This line necessary only if process doesn't wait until threads finish their work (pthread_join).
	return 0;
}
