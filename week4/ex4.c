#include <stdio.h>
#include <stdlib.h>

int main(){
	char s[1000];
	while(1){
		fgets(s,1000,stdin);
		char *args[1000];		
		int t=0,i=0,j=0;
		for(i=0;i<1000;i++){
			args[i]=NULL;
		}
		i=0;
		args[0]=(char*)malloc(1000);	
		while(1){
			if(s[i]!=' ' && s[i]!='\n' && s[i]!='\0'){
				args[t][j]=s[i];
				i++,j++;
			}
			else if(s[i]==' '){
				i++,j=0,t++;
				args[t]=(char*)malloc(1000);
			}
			else{
				break;
			}
		}
		int pid=fork();
		if(pid==0){
			execvp(args[0],args,NULL);
		}
	}
	return 0;
}
