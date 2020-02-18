#include <stdio.h>
int main()
{
	int n,i,min,max;
	scanf("%d",&n);
	for(i=2;i<n;i++)
		if(n%i==0)
		{min=i;break;}
	max=n/min;
	printf("%d",max);
	return 0;
}
