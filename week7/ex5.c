#include <stdio.h>
#include <stdlib.h> //We need malloc function

int main() {
	char **s=(char**)malloc(sizeof(char*));//We need to allocate this pointer
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %s\n",*s);//The string "Hello World" is places in one of second level pointer, which has type char*
	s[0] = foo;
	printf("s[0] is %s\n",s[0]);
	return(0);
}
