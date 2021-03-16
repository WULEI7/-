#include <iostream>
#include <cstdio>
using namespace std;
int n,m,ans;
struct disease
{
	int cost,life;
}a[11][5];
void dfs(int pos,int cos,int lif)
{
	if(pos==n+1)
	{
		if(lif>ans)
			ans=lif;
		return;
	}
	dfs(pos+1,cos,lif);//考虑不救当前疾病的 
	for(int j=1;j<=4;j++)
		if(cos+a[pos][j].cost<=m)
			dfs(pos+1,cos+a[pos][j].cost,lif+a[pos][j].life);//分别考虑四种花费的 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=4;j++)
			cin>>a[i][j].cost>>a[i][j].life;
		ans=0;
		dfs(1,0,0);
		printf("Budget #%d: Maximum of %d lives saved.\n\n",t,ans);
	}
	return 0;
}
