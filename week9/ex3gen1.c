#include <stdio.h>
#include <stdlib.h>

//Program generates page queries made by one process.

FILE *fout;
int pState=-1;

void process(){
	if(pState==-1){
	 	pState=rand()%100;
	}                  	
	else{
	 	if(rand()%(pState+100)<=25)
	 		pState=rand()%100;
	}
	fprintf(fout,"%d %d\n",1,pState);
}

int main(){
	fout=fopen("input4.txt","w");
	int i;
	for(int i=0;i<100000;i++){
	 	process();
	}
	fclose(fout);
 	return 0;
}