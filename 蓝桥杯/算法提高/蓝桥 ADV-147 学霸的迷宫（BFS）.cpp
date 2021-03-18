#include <iostream>
#include <cstdio>
#include <string>
#include <queue> 
using namespace std;
int r,c,vis[505][505];
char qp[505][505];
struct node
{
	int x,y,step;
	string s;
};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
		cin>>qp[i][j];
	queue<node> q;
	node ans;
	q.push({1,1,0,""});
	vis[1][1]=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(t.x==r&&t.y==c)
		{
			ans=t;
			break;
		}
		//×ÖµäÐò£ºD L R U 
		if(t.x+1<=r&&qp[t.x+1][t.y]=='0'&&vis[t.x+1][t.y]==0)
		{
			q.push({t.x+1,t.y,t.step+1,t.s+"D"});
			vis[t.x+1][t.y]=1;
		}
		if(t.y-1>=1&&qp[t.x][t.y-1]=='0'&&vis[t.x][t.y-1]==0)
		{
			q.push({t.x,t.y-1,t.step+1,t.s+"L"});
			vis[t.x][t.y-1]=1;
		}
		if(t.y+1<=c&&qp[t.x][t.y+1]=='0'&&vis[t.x][t.y+1]==0)
		{
			q.push({t.x,t.y+1,t.step+1,t.s+"R"});
			vis[t.x][t.y+1]=1;
		}
		if(t.x-1>=1&&qp[t.x-1][t.y]=='0'&&vis[t.x-1][t.y]==0)
		{
			q.push({t.x-1,t.y,t.step+1,t.s+"U"});
			vis[t.x-1][t.y]=1;
		}
	}
	cout<<ans.step<<endl<<ans.s<<endl;
	return 0;
}
