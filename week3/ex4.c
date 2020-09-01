#include <stdio.h>
#include <stdlib.h>

void Quicksort(int n,int *a,int l,int r){
	int size1=0,size2=0,pivot=a[l];
	int *a1=(int*)malloc(n*sizeof(int));
	int *a2=(int*)malloc(n*sizeof(int));
	for(int i=l+1;i<=r;i++){
	 	if(a[i]<=pivot){
	 		a1[size1]=a[i];
	 		size1++;
	 	}
	 	else{
	 	 	a2[size2]=a[i];
	 	 	size2++;
	 	}
	}
	for(int i=l;i<=r;i++){
	 	if(i-l<size1){
	 	 	a[i]=a1[i-l];
	 	}
	 	else if(i-l==size1){
	 	 	a[i]=pivot;
	 	}
	 	else{
	 		a[i]=a2[i-l-size1-1];
	 	}
	}                         	
	if(size1>=1){
	 	Quicksort(n,a,l,l+size1-1);
	}
	if(size2>=1){
	 	Quicksort(n,a,l+size1+1,r);
	}
}
                         
int main(){      
    int n;
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	Quicksort(n,a,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}