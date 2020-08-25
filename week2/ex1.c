#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){              
	int a;
	float b;
	double c;

	a=INT_MAX;
	b=FLT_MAX;
	c=DBL_MAX;
                                      
	printf("%d %d\n",sizeof(a),a);
	printf("%d %e\n",sizeof(b),b);
	printf("%d %e\n",sizeof(c),c);
 	return 0;
}