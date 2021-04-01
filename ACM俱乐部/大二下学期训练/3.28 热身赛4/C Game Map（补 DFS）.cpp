#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100005;
vector<int> G[maxn];
int n,m,ans=0,dp[maxn];
void dfs(int x,int len)
{
	ans=max(ans,len+dp[x]);//更新答案 
	if(dp[x]>0) return;
	int size=G[x].size();
	for(int i=0;i<size;i++)
	{
		if(G[G[x][i]].size()>G[x].size())
		{
			dfs(G[x][i],len+1);
            dp[x]=max(dp[G[x][i]]+1,dp[x]);//当前结点往后的最大长度 
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<n;i++)
		dfs(i,1);
	cout<<ans<<endl;
	return 0;
}
