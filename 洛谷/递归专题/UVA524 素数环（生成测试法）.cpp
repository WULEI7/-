#include <bits/stdc++.h>
using namespace std;
int isprime(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	int i,j=1,n,ok,a[20];
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case %d:\n",j++);
		for(i=0;i<n;i++)
			a[i]=i+1;
		do
		{
			ok=1;
			for(i=0;i<n;i++)
				if(isprime(a[i]+a[(i+1)%n])==0)
				{ok=0;break;}
			if(ok)
			{
				for(i=0;i<n;i++)
					printf("%d ",a[i]);
				printf("\n");
			}
		}while(next_permutation(a+1,a+n));
		printf("\n");
	}
	return 0;
}
