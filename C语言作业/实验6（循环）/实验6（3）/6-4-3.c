#include <stdio.h>
int main()
{
	int n,a;
	for(n=1;n<=1000;n++)
	{
		if(n%5==2&&n%7==3&&n%3==1) a=n;
	}
	printf("%d",a);
	return 0;
}
