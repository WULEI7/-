#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
	int from,to,w;
};
vector<node> map[10005];
int n,maxn,far,vis[10005];
int dfs(int x,int dis)
{
	vis[x]=1;
	int flag=0;
	int size=map[x].size();
	for(int i=0;i<size;i++)
		if(!vis[map[x][i].to])
		{
			flag=1;
			vis[map[x][i].to]=1;
			dfs(map[x][i].to,dis+map[x][i].w);
			vis[map[x][i].to]=0;
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
		map[a].push_back({a,b,c});
		map[b].push_back({b,a,c});
	}
	memset(vis,0,sizeof(vis));
	dfs(1,0);
	memset(vis,0,sizeof(vis));
	dfs(far,0);
	ans=(maxn+21)*maxn/2;
	cout<<ans<<endl;
	return 0;
}
