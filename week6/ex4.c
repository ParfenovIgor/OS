#include <stdio.h>
#include <stdlib.h>
#define BUFFER 500001
#define MAX_TICKETS 10

//Round robin
//For data2.txt file pushed in stdin with k=10 appended and random number of tickets from 1 to 10 given to every process the average running time of processes is 2.5% of their lifetime.

struct process{
  	int ArrivalTime,BurstTime,ID;
};

void MergeSort(int n,int l,int r,struct process *list){
 	if(r-l!=0){
 		int m=(l+r)/2;          
  	    MergeSort(n,l,m,list);
 	    MergeSort(n,m+1,r,list);                                                    
 		struct process *buffer=(struct process*)malloc((r-l+1)*(sizeof(struct process)));
 		int ptr1=l,ptr2=m+1,ptr3=0;
 		int i;
 		for(i=l;i<=r;i++){
 		 	if(ptr2==r+1){
 		 	 	buffer[ptr3]=list[ptr1];
 		 	 	ptr1++;
 		 	}
 		 	else if(ptr1==m+1){
 		 	 	buffer[ptr3]=list[ptr2];
 		 	 	ptr2++;
 		 	}
 		 	else{
 		 	 	if(list[ptr1].ArrivalTime<=list[ptr2].ArrivalTime){
					buffer[ptr3]=list[ptr1];
					ptr1++;
 		 	 	}
 		 	 	else{
 		 	 	 	buffer[ptr3]=list[ptr2];
 		 	 	 	ptr2++;
 		 	 	}
 		 	}
 		 	ptr3++;
 		}
 		for(i=0;i<(r-l+1);i++){
 		 	list[i+l]=buffer[i];
        }               
        free(buffer);
 	}
}

int main(){
	int n,k;
	scanf("%d",&n);
	struct process *list=(struct process*)malloc(n*(sizeof(struct process)));
	int i,j;
	for(i=0;i<n;i++){
	 	int a,b;
	 	scanf("%d %d",&a,&b);
	 	list[i].ArrivalTime=a;
	 	list[i].BurstTime=b;
	 	list[i].ID=i;
	}
	scanf("%d",&k);     
	int *CT=(int*)malloc(n*sizeof(int));
	int *TAT=(int*)malloc(n*sizeof(int));
	int *WT=(int*)malloc(n*sizeof(int));
	char **Table=(char**)malloc(n*sizeof(char*));
	int SumTAT=0;
	int SumWT=0;
	int CurrentTime=0;
	int *partExecuted=(int*)malloc(n*sizeof(int));
	int *tickets=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		partExecuted[i]=0;  	
		tickets[i]=0;
		Table[i]=(char*)malloc(BUFFER*sizeof(char));
		for(j=0;j<BUFFER;j++){
			Table[i][j]='-';
		}
	}                                                          
	int TotalExecuted=0;
	while(TotalExecuted<n){
		for(i=0;i<n;i++){
		 	if(partExecuted[i]==0 && list[i].ArrivalTime<=CurrentTime && tickets[i]==0){
				tickets[i]=rand()%MAX_TICKETS+1;
		 	}
		}
		int sumTickets=0;
		for(i=0;i<n;i++){
		 	sumTickets+=tickets[i];
		}
		if(sumTickets==0)
			CurrentTime++;
		else{
		 	int ticket=rand()%sumTickets;
		 	int PID=-1;        
		 	for(i=0;i<n;i++){
		 	 	if(tickets[i]>ticket){
		 	 	 	PID=i;
		 	 	 	break;
		 	 	}
		 	 	else
		 	 		ticket-=tickets[i];
		 	}                  
	 		if(list[PID].BurstTime-partExecuted[PID]>k){
				partExecuted[PID]+=k;
				for(i=CurrentTime;i<CurrentTime+k;i++)
					Table[PID][i]='+';
 				CurrentTime+=k;
 			}
 			else{                     
 				for(i=CurrentTime;i<CurrentTime+list[PID].BurstTime-partExecuted[PID];i++)
					Table[PID][i]='+';                    
 			 	CurrentTime+=list[PID].BurstTime-partExecuted[PID];
 			 	partExecuted[PID]=list[PID].BurstTime;
 			 	TotalExecuted++;
 			 	tickets[PID]=0;       
 			 	CT[PID]=CurrentTime;
 			 	TAT[PID]=CurrentTime-list[PID].ArrivalTime;
 			 	WT[PID]=TAT[PID]-list[PID].BurstTime;
 			 	SumTAT+=TAT[PID];
 			 	SumWT+=WT[PID];
 			}         
		}
	}                

	printf("_________________________________\n");
	printf("|Process|CT     |TAT    |WT     |\n");
	printf("_________________________________\n");
    for(i=0;i<n;i++){
    	printf("|%7d|%7d|%7d|%7d|\n",i+1,CT[i],TAT[i],WT[i]);
		printf("_________________________________\n");
    }
    printf("\n");             
	printf("Average turn around time = %f\n",SumTAT*1.0/n);
	printf("Average waiting time     = %f\n",SumWT*1.0/n);
	printf("\n");
	for(i=0;i<n;i++){
	 	printf("%Process %7d|",i+1);
	 	for(j=0;j<CurrentTime;j++)
	 		printf("%c",Table[i][j]);
	 	printf("\n");	
	}
 
	free(list);
	free(CT);
	free(TAT);
	free(WT);
	free(partExecuted);
	free(tickets);
	for(i=0;i<n;i++)
		free(Table[i]);
	free(Table);	
	return 0;
}
