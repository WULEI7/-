#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,l,k,ans=0;
int c[105],u[5005],v[5005],d[5005],vis[5005];
vector<int> adj[5005];
map<pair<int,int>,int> mp;
void dfs(int x,int num,int len)
{
	//cout<<"当前访问"<<x<<endl;
	if(num>l) return;
	if(x==n-1)
	{
		if(len>ans)
			ans=len;
		return;
	}
	for(int i=0;i<adj[x].size();i++)
	{
		int y=adj[x][i];
		if(!vis[y])
		{
			vis[y]=1;
			dfs(y,num+1,len+mp[{x,y}]);
			vis[y]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>l>>k;
	for(int i=0;i<n;i++)
		cin>>c[i];
	for(int i=0;i<m;i++)
		cin>>u[i];
	for(int i=0;i<m;i++)
	{
		cin>>v[i];
		adj[u[i]].emplace_back(v[i]);
	}
	for(int i=0;i<m;i++)
	{
		cin>>d[i];
		mp[{u[i],v[i]}]=d[i];
	}
	vis[0]=1;
	dfs(0,1,0);
	cout<<ans<<endl;
	return 0;
}