#include <stdio.h>

int main(){
	FILE *file=fopen("/dev/random","r");
	char str[21];
	fscanf(file,"%20s",str);
	printf("%20s\n",str);
	fflush(stdout);
	file=fopen("ex1.txt","w");
	fprintf(file,"%20s",str);
	close(file);
	return 0;
}
