#include <iostream>
#include <cstdio>
using namespace std;
int n,map[505][505],cnt[505]; 
void dfs(int x,int y,int k)
{
	if(cnt[k]==0) return;
	if(!map[x][y-1]&&y-1>=1)
	{
		map[x][y-1]=map[k][k];
		cnt[k]--;
		dfs(x,y-1,k);
	}
	else if(!map[x+1][y]&&x+1<=n)
	{
		map[x+1][y]=map[k][k];
		cnt[k]--;
		dfs(x+1,y,k);
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>map[i][i];
		cnt[i]=map[i][i]-1;
	}
	for(int i=1;i<=n;i++)
		dfs(i,i,i);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
