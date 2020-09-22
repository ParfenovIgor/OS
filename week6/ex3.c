#include <stdio.h>
#include <stdlib.h>

//Round robin
//For data2.txt file pushed in stdin with k=10 appended the average running time of processes is 2.4% of their lifetime.

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
	int i;
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
	int SumTAT=0;
	int SumWT=0;
	int CurrentTime=0;
	int *partExecuted=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		partExecuted[i]=0;  	
	}
	int TotalExecuted=0;
	while(TotalExecuted<n){
		int flag=0;
	 	for(i=0;i<n;i++){
	 	 	if(partExecuted[i]<list[i].BurstTime && list[i].ArrivalTime<=CurrentTime){
	 	 		flag=1;
	 			if(list[i].BurstTime-partExecuted[i]>k){
	 				partExecuted[i]+=k;
	 				CurrentTime+=k;
	 			}
	 			else{
	 			 	CurrentTime+=list[i].BurstTime-partExecuted[i];
	 			 	partExecuted[i]=list[i].BurstTime;
	 			 	TotalExecuted++;
	 			 	CT[i]=CurrentTime;
	 			 	TAT[i]=CurrentTime-list[i].ArrivalTime;
	 			 	WT[i]=TAT[i]-list[i].BurstTime;
	 			 	SumTAT+=TAT[i];
	 			 	SumWT+=WT[i];
	 			}
	 	 	}
	 	}
	 	if(!flag)
	 		CurrentTime++;                 
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
	free(partExecuted);
	return 0;
}
