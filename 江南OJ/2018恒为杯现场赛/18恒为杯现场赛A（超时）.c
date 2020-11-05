#include <stdio.h>
int main()
{
	int n,i,j,k,l=0,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=i;
		while(k!=0)
		{
		l+=k%10;
		k/=10;
		}
		if(l%3==0) sum++;
	}
	printf("%d",sum);
	return 0;
}
