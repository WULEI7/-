#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int dix[8]={1,2,2,1,-1,-2,-2,-1},diy[8]={2,1,-1,-2,-2,-1,1,2};
int n,m,x,y,dis[405][405];
void bfs(int x,int y)
{
	queue<pair<int,int> > q;
	q.push({x,y});
	dis[x][y]=0;
	while(!q.empty())
	{
		int tx=q.front().first,ty=q.front().second;
		q.pop();
		for(int i=0;i<8;i++)
		{
			int newx=tx+dix[i],newy=ty+diy[i];
			if(newx>=1&&newx<=n&&newy>=1&&newy<=m&&dis[newx][newy]==-1)
			{
				q.push({newx,newy});
				dis[newx][newy]=dis[tx][ty]+1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>x>>y;
	memset(dis,-1,sizeof(dis));
	bfs(x,y);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%-5d",dis[i][j]);
		printf("\n");
	}
	return 0;
}
