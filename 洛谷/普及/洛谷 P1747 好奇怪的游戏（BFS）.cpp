#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int dix[12]={1,2,2,1,-1,-2,-2,-1,2,2,-2,-2},diy[12]={2,1,-1,-2,-2,-1,1,2,2,-2,2,-2};
int x1,y1,x2,y2,vis[30][30];
struct node
{
	int x,y,dis;
};
int bfs(int x,int y)
{
	queue<node> q;
	q.push({x,y,0});
	while(!q.empty())
	{
		node p=q.front();
		q.pop();
		if(p.x==1&&p.y==1)
			return p.dis;
		for(int i=0;i<12;i++)
		{
			node t;
			t.x=p.x+dix[i];
			t.y=p.y+diy[i];
			t.dis=p.dis+1;
			if(t.x>=1&&t.x<=22&&t.y>=1&&t.y<=22&&!vis[t.x][t.y])
			{
				q.push(t);
				vis[t.x][t.y]=1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>x1>>y1>>x2>>y2;
	cout<<bfs(x1,y1)<<endl;
	memset(vis,0,sizeof(vis));
	cout<<bfs(x2,y2)<<endl;
	return 0;
}
