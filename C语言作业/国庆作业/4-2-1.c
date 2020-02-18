#include <stdio.h>
int main()
{
	int a,b;
	float x;
	scanf("%d,%d",&a,&b);
	x=(float)2*a*b/(a+b)/(a+b);
	printf("x=%f\n",x);
	return 0;
}
