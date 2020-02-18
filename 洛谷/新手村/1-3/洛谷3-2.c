#include <stdio.h>
int main()
{
	double s=0;
	int k,n=0;
	scanf("%d",&k);
	while(s<=k)
	{
		n++;
		s=s+1.0/n;
	}
	printf("%d",n);
	return 0;
}
