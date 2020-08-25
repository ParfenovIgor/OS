#include <stdio.h>

int main(int argc,char *argv[]){
    if(argc==2){
        int n;
        sscanf(argv[1],"%d",&n);
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
	else{
	 	printf("Error, expected numberOfArguments=1");
	}
 	return 0;
}
