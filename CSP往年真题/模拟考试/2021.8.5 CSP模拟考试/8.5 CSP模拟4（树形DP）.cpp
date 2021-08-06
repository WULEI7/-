#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[505];
int vis[505],dp[505][2];
void dfs(int node)
{
	if(vis[node]) return;
	vis[node]=1;
	dp[node][0]=0;
	dp[node][1]=1;
	int size=v[node].size();
	if(size==0) return;
	for(int i=0;i<size;i++)
	{
		int to=v[node][i];
		if(vis[to]) continue;
		dfs(to);
		dp[node][0]+=dp[to][1];
		dp[node][1]+=min(dp[to][0],dp[to][1]);
	}
}
int main()
{
	int n,m,node,num,to;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d:(%d)",&node,&num);
		for(int j=0;j<num;j++)
		{
			scanf("%d",&to);
			v[node].emplace_back(to);
			v[to].emplace_back(node);
		}
	}
	dfs(m);
	printf("%d\n",dp[m][1]);
	return 0;
}
