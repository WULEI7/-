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
	queue<node> q;//BFS���� 
	q.push({sx,sy,0,6});//��������� 
	vis[sx][sy]=6;//���Ѫ�� 
	while(!q.empty()&&cantflag)
	{
		node t=q.front();
		q.pop();
		if(t.hp==1) continue;
		for(int i=0;i<4;i++)
		{
			if(g[t.x+d[i][0]][t.y+d[i][1]])//���Ե��� 
			if(t.hp>vis[t.x+d[i][0]][t.y+d[i][1]])//�����Ժ�ʣ��Ѫ������ͬʱ�������أ� 
			{
				node r;//��״̬ 
				r.hp=t.hp-1;
				r.step=t.step+1;
				r.x=t.x+d[i][0];
				r.y=t.y+d[i][1];
				if(g[r.x][r.y]==3)//�յ� 
				{
					cantflag=0;
					ans=r.step;
					break;
				}
				if(g[r.x][r.y]==4)//��� 
					r.hp=6;
				vis[r.x][r.y]=r.hp;
				q.push(r);//��״̬������� 
			}
		}
	}
	if(cantflag) cout<<"-1"<<endl;//���ܵ����յ� 
	else cout<<ans<<endl;//���Ե������� 
	return 0;
}
