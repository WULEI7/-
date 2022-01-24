#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,m,sx,sy,cantflag=1,ans,g[20][20],vis[20][20];
int d[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
struct node
{
	int x,y,step,hp;
};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>g[i][j];
		if(g[i][j]==2)
		{sx=i;sy=j;}
	}
	queue<node> q;//BFS队列 
	q.push({sx,sy,0,6});//起点加入队列 
	vis[sx][sy]=6;//起点血量 
	while(!q.empty()&&cantflag)
	{
		node t=q.front();
		q.pop();
		if(t.hp==1) continue;
		for(int i=0;i<4;i++)
		{
			if(g[t.x+d[i][0]][t.y+d[i][1]])//可以到达 
			if(t.hp>vis[t.x+d[i][0]][t.y+d[i][1]])//到达以后剩余血量更大（同时进行判重） 
			{
				node r;//新状态 
				r.hp=t.hp-1;
				r.step=t.step+1;
				r.x=t.x+d[i][0];
				r.y=t.y+d[i][1];
				if(g[r.x][r.y]==3)//终点 
				{
					cantflag=0;
					ans=r.step;
					break;
				}
				if(g[r.x][r.y]==4)//鼠标 
					r.hp=6;
				vis[r.x][r.y]=r.hp;
				q.push(r);//新状态加入队列 
			}
		}
	}
	if(cantflag) cout<<"-1"<<endl;//不能到达终点 
	else cout<<ans<<endl;//可以到达，输出答案 
	return 0;
}
