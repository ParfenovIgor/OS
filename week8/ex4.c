#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/resource.h>


//Number in column 'free' decreases every second by 10Mb starting from ~190Mb. After program finishes, the number in column 'free' becomes ~190 Mb.
//Number in columns 'bi' and 'bo' are both always equal to 0.

//After calling 'top' number in column 'VIRT' increases up to ~106000.
//After calling 'top' number in column 'RES' increases up to ~103000.
//After calling 'top' number in column '%MEM' increases up to ~10.

int main(){
	int i;
	for(i=0;i<10;i++){
		int *a=(int*)malloc(10485760);
		memset(a,0,10485760);
		struct rusage ru;
		getrusage(RUSAGE_SELF,&ru);
		printf("Memory usage: %d\n",(int)ru.ru_maxrss);
		sleep(1);
	}
	return 0;
}
