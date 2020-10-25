#include <iostream>
#include <cstdio>
using namespace std;
long long v[100005],t[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&v[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&t[i]);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		long long ans=0;
		for(int j=1;j<=i;j++)
		{
			if(v[j]==0) continue;
			if(v[j]-t[i]>=0)
			{
				v[j]-=t[i];
				ans+=t[i];
			}
			else
			{
				ans+=v[j];
				v[j]=0;
			}
		}
		printf("%lld ",ans);
	}
	printf("\n");
	return 0;
}
