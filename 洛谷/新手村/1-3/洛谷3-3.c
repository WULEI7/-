#include <stdio.h>
int main()
{
	double x=2,y=0,s;
	int n=0;
	scanf("%lf",&s);
	while(y<s)
	{
		y=y+x;
		x=0.98*x;
		n++;
	}
	printf("%d",n);
	return 0;
}
