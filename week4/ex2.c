#include <stdio.h>
#include <stdlib.h>

//Process, which expects to execute n fork-s, executes processes, which expect to execute n-1, n-2 ...,0 fork-s.

//For 3 fork() executions - 8 processes are created.
//0 -- 0 -- 0 -- 0
//     |    |
//     |    0
//     |
//     | -- 0 -- 0
//     |
//     0

//For 5 fork() executions - 32 processes are created.

int main(){
	int i;
	for(i=0;i<5;i++){
		fork();
	}
	sleep(5);
	return 0;
}
