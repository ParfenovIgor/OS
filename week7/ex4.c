#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a,int b){
	if(a<=b)
		return a;
	else
		return b;
}

void *_realloc(void *ptr,size_t size){
	if(ptr==NULL){
		return malloc(size);
	}
	if(size==0){
		free(ptr);
		return NULL;
	}
	size_t old_size=malloc_usable_size(ptr);
	void *ptr2=malloc(size);
	memcpy(ptr2,ptr,(size_t)(min(size,old_size)));
	ptr=ptr2;
	free(ptr);
}

int main(){
	int *a=(int*)malloc(10*sizeof(int));
	int i;
	for(i=0;i<10;i++){
		a[i]=i;
	}
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	_realloc(a,4*sizeof(int));
	for(i=0;i<4;i++){
		printf("%d ",a[i]);
	}
	printf("\n");

	
	char *b=(char*)malloc(16*sizeof(char));
	char j;
	for(i=0,j='a';j<'p';i++,j++){
		b[i]=j;
	}
	for(i=0;i<16;i++){
		printf("%c ",b[i]);
	}
	printf("\n");
	_realloc(b,26*sizeof(char));
	for(i=0;i<26;i++){
		printf("%c ",b[i]);
	}
	printf("\n");
	return 0;
}
