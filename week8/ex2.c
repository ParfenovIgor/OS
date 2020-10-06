#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Number in column 'free' decreases every second by 10Mb starting from ~190Mb. After program finishes, the number in column 'free' becomes ~190 Mb.
//Number in columns 'bi' and 'bo' are both always equal to 0.

int main(){
	int i;
	for(i=0;i<10;i++){
		int *a=(int*)malloc(10485760);
		memset(a,0,10485760);
		sleep(1);
	}
	return 0;
}
