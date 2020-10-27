#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(){
	struct stat buf;
	int file=open("ex1.txt",O_RDWR);
	
	if(fstat(file,&buf)){
		printf("Cannot get file status\n");
		return 0;
	}

	char *str="This is a nice day\n";
	char *adr=mmap(NULL,strlen(str),PROT_WRITE,MAP_SHARED,file,0);
	strncpy(adr,str,strlen(str));
	ftruncate(file,strlen(str));
	munmap(adr,strlen(str));

	close(file);
	
	return 0;
}

