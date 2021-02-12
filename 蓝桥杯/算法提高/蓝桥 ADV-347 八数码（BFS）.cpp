#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
const int len=362880;//状态共9!=362880种 
using namespace std;
struct node
{
	int state[9];
	int dis;
};
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int vis[len]={0};
int start[9],goal[9];
long factory[10]={1,1,2,6,24,120,720,5040,40320,362880};//0到9的阶乘 
bool Cantor(int str[],int n)//康托展开判重 
{
	long res=0;
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=i+1;j<n;j++)
			if(str[i]>str[j])
				count++;
		res+=count*factory[n-i-1];
	}
	if(!vis[res])//当前状态未访问过 
	{
		vis[res]=1;
		return 1;
	}
	return 0;
}
int bfs()
{
	node head;
	memcpy(head.state,start,sizeof(start));
	head.dis=0;
	queue<node> q;
	Cantor(head.state,9);
	q.push(head);
	while(!q.empty())
	{
		head=q.front();
		if(memcmp(head.state,goal,sizeof(goal))==0)//到达目标状态，返回步数dis 
			return head.dis;
		q.pop();
		int x,y,z;
		for(z=0;z<9;z++)
			if(head.state[z]==0)//找到0的位置 
				break;
		x=z%3;y=z/3;//横纵坐标 
		for(int i=0;i<4;i++)
		{
			int newx=x+dir[i][0];
			int newy=y+dir[i][1];
			int nz=newx+3*newy;
			if(newx>=0&&newx<3&&newy>=0&&newy<3)
			{
				node newnode;
				memcpy(&newnode,&head,sizeof(struct node));
				swap(newnode.state[z],newnode.state[nz]);
				newnode.dis++;
				if(Cantor(newnode.state,9))
					q.push(newnode);
			}
		}
	}
	return -1;//未找到 
}
int main()
{
	for(int i=0;i<9;i++)
		cin>>start[i];
	for(int i=0;i<9;i++)
		cin>>goal[i];
	int num=bfs();
	cout<<num<<endl;
	return 0;
}
