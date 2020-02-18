#include <bits/stdc++.h>
using namespace std;
int n,a[32],vis[32],isp[32];
int isprime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}
void dfs(int cur)
{
	if(cur==n&&isp[a[0]+a[n-1]])
	{
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	else
		for(int i=2;i<=n;i++)
			if(!vis[i]&&isp[i+a[cur-1]])
			{
				a[cur]=i;
				vis[i]=1;
				dfs(cur+1);
				vis[i]=0;
			}
}
int main()
{
	int c=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case %d:\n",c++);
		for(int i=2;i<=n*2;i++)
			isp[i]=isprime(i);
		memset(vis, 0, sizeof(vis));
		a[0]=1;
		dfs(1);
		printf("\n");
	}
	return 0;
}
