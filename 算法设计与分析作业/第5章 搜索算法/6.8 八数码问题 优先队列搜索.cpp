#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
const int len=362880;//状态共9!=362880种 
using namespace std;

int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//四个方向 
int vis[len]={0};//状态访问标记 
int pre[len];//记录上一个状态，用于打印路径 
int start[9],goal[9]={1,2,3,8,0,4,7,6,5};//初始状态和目标状态 
long factory[10]={1,1,2,6,24,120,720,5040,40320,362880};//0到9的阶乘 

struct node//状态结点 
{
	int state[9];
	int dis;
};

int difnum(node a)//不在位的将牌数 
{
	int num=0;
	for(int i=0;i<9;i++)
		if(a.state[i]!=goal[i])
			num++;
	return num;
}

struct cmp//结点权值比较 
{
	bool operator()(node &a,node &b)
	{
		return a.dis+difnum(a)>b.dis+difnum(b);//估价函数值是状态的深度加上不在位的将牌数 
	}
};

int Cantor(int str[],int n)//康托展开 
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=i+1;j<n;j++)
			if(str[i]>str[j])
				count++;
		res+=count*factory[n-i-1];
	}
	return res;
}

stack<int> ans;//存储路径 
void Traceback(int can)//存储路径 
{
	ans.push(can);
	if(can==Cantor(start,9))//回到初始状态 
		return;
	Traceback(pre[can]);
}

void Print()//逆康托展开，打印路径 
{
	while(!ans.empty())
	{
		int quo,res=ans.top(),state[9],vis[9]={0};
		ans.pop();
		for(int i=0;i<9;i++)
		{
			quo=res/factory[9-i-1];
			res=res%factory[9-i-1];
			for(int j=0;j<9;j++)
			{
				if(!vis[j]&&!(quo--))
				{
					state[i]=j;
					vis[j]=1;
					break;
				}
			}
		}
		for(int i=0;i<9;i++)
		{
			cout<<state[i]<<" ";
			if(i%3==2)
				cout<<endl;
		}
		cout<<endl;
	}
}

int bfs()
{
	node head;
	memcpy(head.state,start,sizeof(start));
	head.dis=0;
	priority_queue<node,vector<node>,cmp> q;
	Cantor(head.state,9);
	q.push(head);
	int time=0;
	while(!q.empty())
	{
		time++;
		head=q.top();
		q.pop();
		if(memcmp(head.state,goal,sizeof(goal))==0)//到达目标状态，返回步数dis 
			return head.dis;
		if(time>=3000)//迭代超过3000次 
			return -1;
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
				int newcan=Cantor(newnode.state,9);
				int precan=Cantor(head.state,9);
				if(!vis[newcan])//康托展开判重 
				{
					q.push(newnode);
					vis[newcan]=1;
					pre[newcan]=precan;
				}
			}
		}
	}
	return -1;//未找到 
}

int main()
{
	for(int i=0;i<9;i++)
		cin>>start[i];
	//for(int i=0;i<9;i++)
	//	cin>>goal[i];
	int num=bfs();
	//cout<<num<<endl;
	if(num==-1)
		cout<<"error"<<endl;
	else
	{
		Traceback(Cantor(goal,9));
		Print();
	}
	return 0;
}
