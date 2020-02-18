#include <stdio.h>
int main()
{
	int a=100,i,j;
	float b=1,e=1;
	for(i=1;i<=a;i++){
		b*=i;
		e=e+1/b;
	}
	printf("%.5f",e);
	return 0;
}
