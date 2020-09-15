#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUMBER_OF_PHILOSOPHERS 5
#define NULL_PTHREAD 0
#define THINKING 0
#define EATING 1
typedef int semaphore;

pthread_t tid[NUMBER_OF_PHILOSOPHERS];//Threads' id
int state[NUMBER_OF_PHILOSOPHERS];//Philosophers' state - either THINKING or EATING
pthread_mutex_t mutex;//The mutex for critical region

void* thread_philosopher(void *arg){
	pthread_t id=pthread_self();
	int i,my_id,eating=0;
	for(i=0;i<NUMBER_OF_PHILOSOPHERS;i++){//Find myself in list to get id
		if(pthread_equal(id,tid[i])){
			my_id=i;
			break;
		}
	}
	int left=(my_id-1+NUMBER_OF_PHILOSOPHERS)%NUMBER_OF_PHILOSOPHERS;//Left neighbour
	int right=(my_id+1)%NUMBER_OF_PHILOSOPHERS;//Right neighbour
	
	while(1){
		sleep(1);
		pthread_mutex_lock(&mutex);//Enter critical region
		if(state[my_id]==THINKING){
			if(state[left]==THINKING && state[right]==THINKING){//Check if my neighbours aren't eating
				printf("Philosopher %d starts eating\n",my_id);
				state[my_id]=EATING;
			}
		}
		else{
			printf("Philosopher %d stops eating\n",my_id);	
			state[my_id]=THINKING;
		}
		//Find number of eating philosophers right now
		int sum=0;
		for(i=0;i<NUMBER_OF_PHILOSOPHERS;i++){
			sum+=state[i];	
		}
		printf("%d philosophers are eating\n",sum);
		pthread_mutex_unlock(&mutex);//Leave critical region
	}
}

int main(){
	pthread_mutex_init(&mutex,NULL);//Initialize mutex
	int i;
	for(i=0;i<NUMBER_OF_PHILOSOPHERS;i++){
		pthread_create(&(tid[i]),NULL,&thread_philosopher,NULL);//Run threads
	}
	pthread_join(tid[0],NULL);
	return 0;
}
