#include <stdio.h>
#define MAXN 1000

int E[MAXN],A[MAXN],C[MAXN][MAXN],R[MAXN][MAXN],used[MAXN];

int main(){
	FILE *file;
	file=fopen("input.txt","r");
	int nProcesses,nResources;
	fscanf(file,"%d %d",&nProcesses,&nResources);
	int i,j,k;
	for(i=0;i<nResources;i++){
		fscanf(file,"%d",&E[i]);
	}
	for(i=0;i<nResources;i++){
		fscanf(file,"%d",&A[i]);
	}
	
	for(i=0;i<nProcesses;i++){
		for(j=0;j<nResources;j++){
			fscanf(file,"%d",&C[i][j]);
		}
	}
	for(i=0;i<nProcesses;i++){
		for(j=0;j<nResources;j++){
			fscanf(file,"%d",&R[i][j]);
		}
	}
	
	fclose(file);

	for(i=0;i<nResources;i++){
	 	used[i]=0;
	}
	int nDeadlocked=0;
	for(i=0;i<nProcesses;i++){
	 	int good=-1;
	 	for(j=0;j<nProcesses;j++){
	 		if(used[j])
	 			continue;
	 	    int flag=1;
	 		for(k=0;k<nResources;k++){
				if(R[j][k]>A[k]){
				 	flag=0;
				 	break;
				}
	 		}
	 		if(flag){
	 		 	good=j;
	 		 	break;
	 		}
	 	}
	 	if(good==-1){
	 	    nDeadlocked=nProcesses-i;
	 		break;
	 	}
	 	used[good]=1;
		for(j=0;j<nProcesses;j++){
		 	A[j]+=C[good][j];
		}                   
	}
	
	file=fopen("output.txt","w");

	if(nDeadlocked==0){
		fprintf(file,"No deadlocked processes\n");
	}
	else{
	 	fprintf(file,"%d deadlocked processes:\n",nDeadlocked);
	 	for(i=0;i<nProcesses;i++){
	 	 	if(!used[i])
	 	 		fprintf(file,"%d ",i);
	 	}
	 	fprintf(file,"\n");
	}
	fclose(file);
	

 	return 0;
}