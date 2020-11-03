#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 100000

int main(int argv,char *argc[]){
	char *str[100];
	char tmp[BUFFER];
	int size=0;
	while(fgets(tmp,BUFFER,stdin)!=NULL){
		str[size]=(char*)malloc(BUFFER);
		memcpy(str[size],tmp,BUFFER);
		size++;	
	}
	int append=0;
	int i=1;
	for(;i<argv;i++){
		if(!strcmp(argc[i],"-a")){
			append=1;	
		}
		else{	
			FILE *file;
			if(append)
				file=fopen(argc[i],"a");
			else
				file=fopen(argc[i],"w");
			int j=0;
			for(;j<size;j++)
				fprintf(file,"%s",str[j]);
			fclose(file);
		}
	}
	return 0;
}
