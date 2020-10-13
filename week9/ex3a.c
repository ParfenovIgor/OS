#include <stdio.h>
#define MAXSIZE 10000

//54. Write a program that will demonstrate the difference between using a local page re-
//placement policy and a global one for the simple case of two processes. You will need
//a routine that can generate a page reference string based on a statistical model. This
//model has N states numbered from 0 to N ? 1 representing each of the possible page
//references and a probability pi associated with each state i representing the chance that
//the next reference is to the same page. Otherwise, the next page reference will be one
//of the other pages with equal probability.
//(a) Demonstrate that the page reference string-generation routine behaves properly for
//some small N.
//(b) Compute the page fault rate for a small example in which there is one process and a
//fixed number of page frames. Explain why the behavior is correct.
//(c) Repeat part (b) with two processes with independent page reference sequences and
//twice as many page frames as in part (b).
//(d) Repeat part (c) but using a global policy instead of a local one. Also, contrast the
//per-process page fault rate with that of the local policy approach.
                                                         
//This is implementaion of local page replacement.               
//With given input file and 100 page frames the number of hits is 91299 (91.3%) and number of misses is 8701 (8.7%).

struct page{
 	int address;
 	unsigned int counter;
};
                           
struct page pages[2][MAXSIZE];

int main(){
    FILE *fin;
    fin=fopen("input5.txt","r");
    int SIZE=50;//Number of page frames
    int i;
    for(i=0;i<SIZE;i++){
     	pages[0][i].address=-1;//All frames are empty
		pages[1][i].address=-1;
    }
    int process,query,hits=0,misses=0;
    while(fscanf(fin,"%d %d",&process,&query)!=-1){//Check if there is a number in input file
		int id=-1;
		for(i=0;i<SIZE;i++){//Check if there is query page
		 	if(pages[process-1][i].address==query){
		 	 	id=i;
		 	 	break;
		 	}
     	}
     	if(id!=-1){
     	 	hits++;
     	}
     	else{
     		misses++;
     		int emptyAddress=-1;
     		for(i=0;i<SIZE;i++){//Check if there is empty page frame
     		 	if(pages[process-1][i].address==-1){
     		 	 	emptyAddress=i;
     		 	 	break;
     		 	}
     		}
     		if(emptyAddress!=-1){
     		 	pages[process-1][emptyAddress].address=query;
     		 	id=emptyAddress;
     		}
     		else{
     		 	int Min=-1;
     		 	for(i=0;i<SIZE;i++){//Find the page with least counter
     		 		if(Min==-1 || pages[process-1][i].counter<pages[process-1][Min].counter){
     		 		 	Min=i;
     		 		}
     		 	}
     		 	pages[process-1][Min].address=query;
     		 	id=Min;
     		}
     	}
     	for(i=0;i<SIZE;i++){//Update counters
     	 	pages[process-1][i].counter>>=1;
     	}
     	pages[process-1][id].counter|=(1u<<31);
    }
    printf("Number of hits: %d\nNumber of misses: %d\n",hits,misses);
    fclose(fin);
 	return 0;
}
