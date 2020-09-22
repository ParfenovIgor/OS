#include <stdio.h>
#include <stdlib.h>

//First come, first served
//For data2.txt file pushed in stdin the average running time of processes is 3.6% of their lifetime.

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
	int n;
	scanf("%d",&n);
	struct process *list=(struct process*)malloc(n*(sizeof(struct process)));
	int i;
	for(i=0;i<n;i++){
	 	int a,b;
	 	scanf("%d %d",&a,&b);
	 	list[i].ArrivalTime=a;
	 	list[i].BurstTime=b;
	 	list[i].ID=i;
	}
	MergeSort(n,0,n-1,list);                           
	int *CT=(int*)malloc(n*sizeof(int));
	int *TAT=(int*)malloc(n*sizeof(int));
	int *WT=(int*)malloc(n*sizeof(int));
	int SumTAT=0;
	int SumWT=0;
	int CurrentTime=0;
	for(i=0;i<n;i++){
		int Wait=0;
	 	if(list[i].ArrivalTime>CurrentTime){
	 	 	CurrentTime=list[i].ArrivalTime;
	 	}
	 	else{
	 	 	Wait=CurrentTime-list[i].ArrivalTime;
	 	}
	 	CT[list[i].ID]=CurrentTime+list[i].BurstTime;
	 	TAT[list[i].ID]=Wait+list[i].BurstTime;
	 	WT[list[i].ID]=Wait;
	 	SumTAT+=TAT[list[i].ID];
	 	SumWT+=WT[list[i].ID];
	 	CurrentTime+=list[i].BurstTime;
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

	free(list);
	free(CT);
	free(TAT);
	free(WT);
	return 0;
}
