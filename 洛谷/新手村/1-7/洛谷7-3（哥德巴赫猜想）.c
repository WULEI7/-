#include <stdio.h>
int isprime(int m)
{
	int i,flag=1;
	for(i=2;i<m;i++)
	{
		if(m%i==0)
		{flag=0;break;}
	}
	return flag;
}
int main()
{
	int n,a,b,c,pd=0;
	scanf("%d",&n);
	for(a=2;a<n;a++)
	{
		for(b=2;b<n-a;b++)
		{
			for(c=2;c<=n-a-b;c++)
			{
				if(a+b+c==n&&isprime(a)==1&&isprime(b)==1&&isprime(c)==1)
				{printf("%d %d %d",a,b,c);pd=1;break;}
			}
			if(pd==1) break;
		}
		if(pd==1) break;
	}
	return 0;
}
