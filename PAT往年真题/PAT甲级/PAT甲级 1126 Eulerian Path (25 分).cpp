#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int vis[505],d[505];//每个点的度数 
vector<int> g[505];//邻接表 
int n,m,u,v,sum=0,cnt=0;
void dfs(int t)
{
	sum++;
	vis[t]=1;
	for(int i=0;i<g[t].size();i++)
		if(!vis[g[t][i]])
			dfs(g[t][i]);
}//判断整个图是否连通 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
		d[u]++;
		d[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]%2) cnt++;
		i!=1?cout<<' '<<d[i]:cout<<d[i];
	}
	dfs(1);
	if(sum==n&&cnt==0)
		cout<<endl<<"Eulerian"<<endl;
	else if(sum==n&&cnt==2)
		cout<<endl<<"Semi-Eulerian"<<endl;
	else
		cout<<endl<<"Non-Eulerian"<<endl;
	return 0;
}
