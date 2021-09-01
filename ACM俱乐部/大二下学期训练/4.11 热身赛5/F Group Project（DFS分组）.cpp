#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int vis[maxn];
vector<int> g[maxn];

void dfs(int u,int p)
{
	if(vis[u]) return;
	vis[u]=p;
	for(auto v:g[u]) 
		dfs(v,p==1?2:1);
}

int main()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,1);
	int s=count(begin(vis),end(vis),1);
	int t=count(begin(vis),end(vis),2);
	if(s+t==n&&s*t==m)
		cout<<s/2+t/2<<endl;
	else
		cout<<n/2<<endl;
}
