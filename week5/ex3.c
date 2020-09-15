#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NULL_PTHREAD 0
#define MAX_BUFFER 1000000

int buffer=0;//Objects, which makes producer, and takes consumer
int producer_enabled=1;
int consumer_enabled=0;
pthread_t thread_producer,thread_consumer;

void* producer(void *arg){
	int i=0;
	while(1){
		while(buffer==MAX_BUFFER);//Wait until buffer is not full
		if(i%1000==0)
			printf("Producer %d %d\n",i,buffer);//Output number of made product and the size of buffer
		if(buffer<MAX_BUFFER){//Make product
			i++;
			buffer++;
		}
	}
}

void* consumer(void *arg){
	int i=0;
	while(1){
		while(buffer==0);//Wait until buffer is not empty
		if(i%1000==0)
			printf("Consumer %d %d\n",i,buffer);//Output number of taken product and the size of buffer
		if(buffer>0){//Take product
			i++;
			buffer--;
		}
	}
}

//We don't use here any protection mechnisms.
//If maximum size of buffer is big enough (100000+), then we can notice following: the first output of one thread after outputs of another thread contains incorrect size of buffer. This happened, because right during the printf execution the thread was blocked, and after beeing activated, it contains old value. This is race condition. The result of program is incorrect.

int main(){
	pthread_create(&thread_producer,NULL,&producer,NULL);
	pthread_create(&thread_consumer,NULL,&consumer,NULL);
	pthread_join(thread_producer,NULL);
	return 0;
}
