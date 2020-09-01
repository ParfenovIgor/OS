#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int n,int *a){
 	for(int i=0;i<n;i++){
 	 	for(int j=0;j<n-1;j++){
 	 	 	if(a[j]>a[j+1]){
 	 	 	 	int t=a[j];
 	 	 	 	a[j]=a[j+1];
 	 	 	 	a[j+1]=t;
 	 	 	}
 	 	}
 	}
}

int main(){           
    int n;
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubble_sort(n,a);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}