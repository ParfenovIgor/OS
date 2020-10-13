#include <stdio.h>

//When any page is asked, it is in frame, except the first time. The number of hits is 999.

int main(){
	FILE *fout;
	fout=fopen("input3.txt","w");
	int i;
	for(i=0;i<1000;i++){
	 	fprintf(fout,"%d ",0);
	}
	fclose(fout);
 	return 0;
}