#include <stdio.h>

//When any page is asked, it is not in frame. The number of hits is 0.

int main(){
	FILE *fout;
	fout=fopen("input2.txt","w");
	int i;
	for(i=0;i<1000;i++){
	 	fprintf(fout,"%d ",i);
	}
	fclose(fout);
 	return 0;
}