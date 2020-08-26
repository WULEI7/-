#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> map[1005];//图 
int vis[1005],know[1005][1005];//保存哪两个结点能互相知道 
void dfs(int s,int v)
{
	vis[v]=1;
	know[s][v]=know[v][s]=1;
	for(int i=0;i<map[v].size();i++)
		if(vis[map[v][i]]==0)
			dfs(s,map[v][i]);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		map[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	{
		fill(vis+1,vis+n+1,0);
		dfs(i,i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(count(know[i]+1,know[i]+n+1,1)==n)
			ans++;
	cout<<ans<<endl;
	return 0;
}
