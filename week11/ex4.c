#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(){
	struct stat buf1,buf2;
	int file1=open("ex1.txt",O_RDWR);
	int file2=open("ex1_memcpy.txt",O_RDWR);
	
	if(fstat(file1,&buf1) || fstat(file2,&buf2)){
		printf("Cannot get file status\n");
		return 0;
	}

	char *adr1=mmap(NULL,buf1.st_size,PROT_READ,MAP_SHARED,file1,0);

	char *str=(char*)malloc(buf1.st_size);
	strncpy(str,adr1,buf1.st_size);

	char *adr2=mmap(NULL,buf1.st_size,PROT_WRITE,MAP_SHARED,file2,0);
	strncpy(adr2,adr1,buf1.st_size);
	ftruncate(file2,buf1.st_size);
	munmap(adr2,buf1.st_size);

	close(file1);
	close(file2);
	
	return 0;
}

