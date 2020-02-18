#include <stdio.h>
int main()
{
	int n,k,sum;
	scanf("%d %d",&n,&k);
	sum=n;
	while(n>=k)
	{
		n=n-k+1;
		sum++;
	}
	printf("%d",sum);
	return 0;
}
