#include <stdio.h>
int main()
{
	int a,b,i,j,sum=0;
	scanf("%d %d",&a,&b);
	for(i=a;i<=b;i++)
	{
		j=i;
		while(j!=0)
		{
			if(j%10==2) sum++;
			j/=10;
		}
	}
	printf("%d",sum);
	return 0;
}
