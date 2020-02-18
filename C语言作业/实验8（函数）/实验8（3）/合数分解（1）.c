#include <stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=2;;)
	{
		if(n%i==0)
		{
			printf("%d ",i);
			n/=i;
		}
		else i++;
		if(n==1) break;
	}
	return 0;
}
