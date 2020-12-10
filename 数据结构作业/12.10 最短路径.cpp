#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define maxn 105
#define inf 999999999//无穷大 
using namespace std;

typedef struct
{
	int arcs[maxn][maxn];//邻接矩阵 
	int vexnum;//顶点数：顶点编号从1至vexnum 
	int arcnum;//边（弧）数 
	int Graphkind;//图的种类（1为有向网，2为无向网） 
}MGraph;//图 

void CreateDN(MGraph &G)//构造有向网G 
{
	cout<<"请输入有向网G的顶点数：";
	cin>>G.vexnum;
	cout<<"请输入有向网G的弧数：";
	cin>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		G.arcs[i][j]=inf;//网的初始化 
	int u,v,w;
	cout<<"请输入每条弧的初始点、终端点和权值："<<endl;
	for(int i=1;i<=G.arcnum;i++)
	{
		cin>>u>>v>>w;
		G.arcs[u][v]=w;
	}
}

void CreateUDN(MGraph &G)//构造无向网G 
{
	cout<<"请输入无向网G的顶点数：";
	cin>>G.vexnum;
	cout<<"请输入无向网G的边数：";
	cin>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		G.arcs[i][j]=inf;//网的初始化 
	int u,v,w;
	cout<<"请输入每条边的两个顶点和权值："<<endl;
	for(int i=1;i<=G.arcnum;i++)
	{
		cin>>u>>v>>w;
		G.arcs[u][v]=w;
		G.arcs[v][u]=w;
	}
}

void CreateGraph(MGraph &G)//构造图G 
{
	cout<<"请输入图的种类（1为有向网，2为无向网）：";
	cin>>G.Graphkind;
	switch(G.Graphkind)
	{
		case 1:CreateDN(G);break;
		case 2:CreateUDN(G);break;
		default:
			cout<<"构造失败！"<<endl;
			return; 
	}
}

void PrintGraph(MGraph G)//打印图G的邻接矩阵 
{
	for(int i=1;i<=G.vexnum;i++)
	{
		for(int j=1;j<=G.vexnum;j++)
		{
			if(G.arcs[i][j]==inf)
				printf("  INF");//表示无穷大 
			else
				printf("%5d",G.arcs[i][j]);
		}
		printf("\n");
	}
}

//求最短路径 
int vis[maxn],dis[maxn];
void Dijkstra(MGraph G,int u)//Dijkstra算法求单源最短路 
{
	memset(vis,0,sizeof(vis));
	int n=G.vexnum;
	for(int i=1;i<=n;i++)
		dis[i]=G.arcs[u][i];//以u为原点 
	dis[u]=0;vis[u]=1;
	for(int i=1;i<n;i++)//选择剩下的n-1个顶点 
	{
		int k=0,minn=inf;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]<minn)
			{
				minn=dis[j];
				k=j;
			}
		if(k==0) break;//此句很重要，因为有的图可能走不通 
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>dis[k]+G.arcs[k][j])
				dis[j]=dis[k]+G.arcs[k][j];
		//输出for循环每一轮后的状态 
		cout<<"第"<<i<<"轮选中的顶点为："<<k<<endl;
		cout<<"第"<<i<<"轮后dis数组的值为：";
		for(int i=1;i<=n;i++)
		{
			if(dis[i]==inf)
				cout<<"INF ";
			else
				cout<<dis[i]<<" ";
		}
		cout<<endl;
	}
}

void Floyd(MGraph &G)//Floyd算法求任意两点最短路 
{
	int n=G.vexnum;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(G.arcs[i][k]+G.arcs[k][j]<G.arcs[i][j])
				G.arcs[i][j]=G.arcs[i][k]+G.arcs[k][j];
		//输出for循环每一轮后的状态 
		cout<<"尝试顶点"<<k<<"后G的邻接矩阵为："<<endl;
		PrintGraph(G);
	}
}

int main()
{
	MGraph G;
	CreateGraph(G);//构造图G 
	cout<<endl;
	cout<<"打印图G的邻接矩阵为："<<endl;
	PrintGraph(G);//打印图G的邻接矩阵 
	cout<<endl;
	cout<<"Dijkstra算法："<<endl;
	Dijkstra(G,1);
	cout<<"用Dijkstra算法求得顶点1和5之间的最短路径长度为："<<dis[5]<<endl;
	cout<<endl;
	cout<<"Floyd算法："<<endl;
	Floyd(G);
	cout<<"用Floyd算法求得顶点1和5之间的最短路径长度为："<<G.arcs[1][5]<<endl;
	return 0;
}
/*
	测试数据：
	
	无向网 
	6
	8
	1 2 5
	2 3 50
	3 5 10
	4 3 20
	4 5 60
	6 2 10
	6 4 30
	6 5 100
	
	有向网 
	6
	9
	1 2 3
	1 6 5
	2 3 8
	3 5 6
	4 3 2
	5 2 4
	5 4 7
	6 2 1
	6 5 2
*/
