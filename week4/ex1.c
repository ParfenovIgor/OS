#include <stdio.h>
#include <stdlib.h>

//The pairs of strings "..child.." and "..parent.." are shuffled. Several cores execute processes of this program simultaneously.

int main(){
	int n=10;
	pid_t pid=fork();
	if(pid==0){
		printf("Hello from child [%d-%d]\n",getpid(),n);
	}
	else{
		printf("Hello from parent [%d-%d]\n",getpid(),n);
	}
	return 0;
}
