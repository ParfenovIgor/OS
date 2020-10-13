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
                                                         
//This is implementaion of global page replacement.               
//With given input file and 100 page frames the number of hits is 999000 (99.9%) and number of misses is 100 (0.01%).

struct page{
 	int address;
 	int counter;
};

struct page pages[MAXSIZE];

int main(){
    FILE *fin;
    fin=fopen("input5.txt","r");
    int SIZE=100;//Number of page frames
    int i;
    for(i=0;i<SIZE;i++){
     	pages[i].address=-1;//All frames are empty
    }
    int process,query,hits=0,misses=0;
    while(fscanf(fin,"%d %d",&process,&query)!=-1){//Check if there is a number in input file
   		int id=-1;
		for(i=0;i<SIZE;i++){//Check if there is query page
		 	if(pages[i].address==query){
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
     	pages[id].counter|=(1<<30);
    }
    printf("Number of hits: %d\nNumber of misses: %d\n",hits,misses);
    fclose(fin);
 	return 0;
}
