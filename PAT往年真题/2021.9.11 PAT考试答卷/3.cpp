#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> G[105];
int n,m,u,v,temps,start,ans=0;
int vis[105];
void DFS(int pos,int dis)
{
	if(dis>ans||dis==ans&&temps<start)
	{
		start=temps;
		ans=dis;
	}
	int size=G[pos].size();
	for(int i=0;i<size;i++)
	{
		if(!vis[G[pos][i]])
		{
			vis[G[pos][i]]=1;
			DFS(G[pos][i],dis+1);
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	for(int i=1;i<=n;i++)
		sort(G[i].begin(),G[i].end());
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		temps=i;
		vis[i]=1;
		DFS(i,1);
	}
	cout<<start<<" "<<ans<<endl;
	return 0;
}
