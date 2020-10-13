#include <stdio.h>
#define MAXSIZE 10000
                                                                                                                 
//With given input file and  10 page frames the number of hits is 10 (1.0%) and number of misses is 990 (99.0%).
//With given input file and  50 page frames the number of hits is 51 (5.1%) and number of misses is 949 (94.9%).
//With given input file and 100 page frames the number of hits is 95 (9.5%) and number of misses is 905 (90.5%).

struct page{
 	int address;
 	unsigned int counter;
};

struct page pages[MAXSIZE];

int main(){
    FILE *fin;
    fin=fopen("input.txt","r");
    int SIZE=10;//Number of page frames
    int i;
    for(i=0;i<SIZE;i++){
     	pages[i].address=-1;//All frames are empty
    }
    int query,hits=0,misses=0;
    while(fscanf(fin,"%d",&query)!=-1){//Check if there is a number in input file
    	printf("%d ",query);
		int id=-1;
		for(i=0;i<SIZE;i++){//Check if there is query page
		 	if(pages[i].address==query){
		 	 	id=i;
		 	 	break;
		 	}
     	}
     	if(id!=-1){
     	 	printf("Hit\n");
     	 	hits++;
     	}
     	else{
     		printf("Miss\n");
     		misses++;
     		int emptyAddress=-1;
     		for(i=0;i<SIZE;i++){//Check if there is empty page frame
     		 	if(pages[i].address==-1){
     		 	 	emptyAddress=i;
     		 	 	break;
     		 	}
     		}
     		if(emptyAddress!=-1){
     		 	pages[emptyAddress].address=query;
     		 	id=emptyAddress;
     		}
     		else{
     		 	int Min=-1;
     		 	for(i=0;i<SIZE;i++){//Find the page with least counter
     		 		if(Min==-1 || pages[i].counter<pages[Min].counter){
     		 		 	Min=i;
     		 		}
     		 	}
     		 	pages[Min].address=query;
     		 	id=Min;
     		}
     	}
     	for(i=0;i<SIZE;i++){//Update counters
     	 	pages[i].counter>>=1;
     	}
     	pages[id].counter|=(1u<<31);
    }
    printf("Number of hits: %d\nNumber of misses: %d\n",hits,misses);
    fclose(fin);
 	return 0;
}
