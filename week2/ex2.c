#include <stdio.h> 
#include <string.h>
#define maxlen 100000

int main(){                           
	char s[maxlen];
	scanf("%s",&s); 
	int n=(int)strlen(s);
	for(int i=0;i<n/2;i++){
	 	char c=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=c;
	}
	printf("%s",s);
 	return 0;
}