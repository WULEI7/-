#include <stdio.h>
void main()
{
	int i,k,j=1,sum=0;
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		j*=i;
		if(i%2==0) continue;
		sum+=j;
	}
	printf("sum=%d\n",sum);
}
