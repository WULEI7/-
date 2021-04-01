#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,ans,dp[100005];
struct disease
{
	int cost,life;
}a[11][5];

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		ans=0;
		memset(dp,0,sizeof(dp));
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=4;j++)
			cin>>a[i][j].cost>>a[i][j].life;
		for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)
		for(int k=1;k<=4;k++)//×¢ÒâÑ­»·Ë³Ðò 
			if(j>=a[i][k].cost)
			{
				dp[j]=max(dp[j],dp[j-a[i][k].cost]+a[i][k].life);
            	ans=max(ans,dp[j]);
			}
		printf("Budget #%d: Maximum of %d lives saved.\n\n",t,ans);
	}
	return 0;
}
