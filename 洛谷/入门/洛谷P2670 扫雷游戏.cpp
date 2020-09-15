#include <cstdio>
#include <iostream>
using namespace std;
char map[105][105];
int ans[105][105];
int x[8]={1,-1,0,0,1,1,-1,-1};
int y[8]={0,0,1,-1,1,-1,1,-1};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>map[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(map[i][j]=='*')
			ans[i][j]=-1;
		else
			for(int k=0;k<8;k++)
			{
				if(i+x[k]>=1&&i+x[k]<=n&&j+y[k]>=1&&j+y[k]<=m)
					if(map[i+x[k]][j+y[k]]=='*')
						ans[i][j]++;
			}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==-1)
				printf("*");
			else
				printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
