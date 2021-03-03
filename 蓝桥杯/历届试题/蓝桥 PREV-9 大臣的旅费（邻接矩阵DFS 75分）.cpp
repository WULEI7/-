#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int map[10005][10005];
int n,maxn,far,vis[10005];
int dfs(int x,int dis)
{
	vis[x]=1;
	int flag=0;
	for(int i=1;i<=n;i++)
		if(map[x][i]>0&&!vis[i])
		{
			flag=1;
			vis[i]=1;
			dfs(i,dis+map[x][i]);
			vis[i]=0;
		}
	if(flag==0)
	{
		if(dis>maxn)
		{
			maxn=dis;
			far=x;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,c,ans;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;
	}
	memset(vis,0,sizeof(vis));
	dfs(1,0);
	memset(vis,0,sizeof(vis));
	dfs(far,0);
	ans=(maxn+21)*maxn/2;
	cout<<ans<<endl;
	return 0;
}
