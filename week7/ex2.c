#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	scanf("%d",&N);

	int *Arr=(int*)malloc(N*sizeof(int));
	
	int i;
	for(i=0;i<N;i++){
		Arr[i]=i;
	}
	for(i=0;i<N;i++){
	 	printf("%d ",Arr[i]);
	}
	
	free(Arr);
 	return 0;
}

