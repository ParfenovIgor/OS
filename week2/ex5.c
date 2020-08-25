#include <stdio.h>

void print1(int n){
        for(int i=0;i<n;i++){
	 	for(int j=0;j<n*2-1;j++){
	 	 	if(j>=n-i-1 && j<=n+i-1){
	 	 	 	printf("*");
			}
			else{
			 	printf(" ");
			}
		}
		printf("\n");
	}
}

void print2(int n){
        for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 	 	if(j<=i){
	 	 	 	printf("*");
			}
			else{
			 	printf(" ");
			}
		}
		printf("\n");
	}
}

void print3(int n){
	for(int i=0;i<(n+1)/2;i++){
	 	for(int j=0;j<n;j++){
	 	 	if(j<=i){
	 	 	 	printf("*");
			}
			else{
			 	printf(" ");
			}
		}
		printf("\n");
	}
	for(int i=0;i<n/2;i++){
	 	for(int j=0;j<n;j++){
	 	 	if(j<=n/2-i-1){
	 	 	 	printf("*");
			}
			else{
			 	printf(" ");
			}
		}
		printf("\n");
	}
}


void print4(int n){
    for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 	 	printf("*");
		}
		printf("\n");
	}
}


int main(int argc,char *argv[]){
	if(argc==2){
		int n;
		sscanf(argv[1],"%d",&n);
		print1(n);
	}
	else if(argc==3){
	 	int t,n;
		sscanf(argv[1],"%d",&t);
		sscanf(argv[2],"%d",&n);
		switch(t){
		 	case 1: print1(n); break;
		 	case 2: print2(n); break;
		 	case 3: print3(n); break;
		 	case 4: print4(n); break;
			default: printf("Error, expected 1<=firstArgument<=4");
		}
	}
	else{
	 	printf("Error, expected 1<=numberOfArguments<=2");
	}
	return 0;
}
