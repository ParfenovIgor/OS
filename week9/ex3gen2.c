#include <stdio.h>
#include <stdlib.h>

//Program generates page queries made by two process.

FILE *fout;                                 
int p1State=-1;
int p2State=-1;
                             
void process1(){
	if(p1State==-1){
	 	p1State=rand()%100;
	}                  	
	else{
	 	if(rand()%(p1State+100)<=25)
	 		p1State=rand()%100;
	}
	fprintf(fout,"%d %d\n",1,p1State);
}

void process2(){
	if(p2State==-1){
	 	p2State=rand()%100;
	}                  	
	else{
	 	if(rand()%(p2State+100)<=25)
	 		p2State=rand()%100;
	}
	fprintf(fout,"%d %d\n",2,p2State);
}

int main(){
	fout=fopen("input5.txt","w");
	int i;
	for(int i=0;i<100000;i++){   
		if(rand()%2==0)
			process1();
		else
			process2();
	}
	fclose(fout);
 	return 0;
}