#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define N 100

struct node{
	int id,size;
	char *names[N];
};

int main(){
	DIR *dirp;
	struct dirent *dp;
	dirp=opendir("tmp");
	if(dirp==NULL){
		printf("Error\n");
		return 1;
	}
	struct node nodes[N];
	int i=0;
	for(i=0;i<N;i++){
		nodes[i].id=-1;
		nodes[i].size=0;
	}
	while((dp=readdir(dirp))!=NULL){
		int cur_id=(int)dp->d_ino;
		char *cur_name=dp->d_name;
		int len=strlen(dp->d_name);
		int flag=-1;
		for(i=0;i<N;i++){
			if(nodes[i].id==cur_id){
				flag=i;
				break;
			}
		}
		if(flag==-1){
			for(i=0;i<N;i++){
				if(nodes[i].id==-1){
					flag=i;
					break;
				}
			}
		}
		nodes[flag].id=cur_id;	
		nodes[flag].names[nodes[flag].size]=(char*)malloc((size_t)len);
		strcpy(nodes[flag].names[nodes[flag].size],dp->d_name);
		nodes[flag].size++;
	}

	for(i=0;i<N;i++){
		if(nodes[i].id!=-1 && nodes[i].size>=2){
			printf("%d ",nodes[i].id);
			int j;
			for(j=0;j<nodes[i].size;j++){
				printf("%s ",nodes[i].names[j]);
			}
			printf("\n");
		}		
	}

	closedir(dirp);
	return 0;
}
