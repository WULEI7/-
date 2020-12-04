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
	int Graphkind;//图的种类（1为有向图，2为有向网，3为无向图，4为无向网） 
}MGraph;//图 

void CreateDG(MGraph &G)//构造有向图G 
{
	cout<<"请输入有向图G的顶点数：";
	cin>>G.vexnum;
	cout<<"请输入有向图G的弧数：";
	cin>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		G.arcs[i][j]=0;//图的初始化 
	int u,v;
	cout<<"请输入每条弧的初始点和终端点："<<endl;
	for(int i=1;i<=G.arcnum;i++)
	{
		cin>>u>>v;
		G.arcs[u][v]=1;
	}
}

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

void CreateUDG(MGraph &G)//构造无向图G 
{
	cout<<"请输入无向图G的顶点数：";
	cin>>G.vexnum;
	cout<<"请输入无向图G的边数：";
	cin>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		G.arcs[i][j]=0;//图的初始化 
	int u,v;
	cout<<"请输入每条边的两个顶点："<<endl;
	for(int i=1;i<=G.arcnum;i++)
	{
		cin>>u>>v;
		G.arcs[u][v]=1;
		G.arcs[v][u]=1;
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
	cout<<"请输入图的种类（1为有向图，2为有向网，3为无向图，4为无向网）：";
	cin>>G.Graphkind;
	switch(G.Graphkind)
	{
		case 1:CreateDG(G);break; 
		case 2:CreateDN(G);break;
		case 3:CreateUDG(G);break;
		case 4:CreateUDN(G);break;
		default:
			cout<<"构造失败！"<<endl;
			return; 
	}
}

void PrintGraph(MGraph G)//打印图G的邻接矩阵 
{
	printf("图G的邻接矩阵为：\n");
	for(int i=1;i<=G.vexnum;i++)
	{
		for(int j=1;j<=G.vexnum;j++)
		{
			if(G.arcs[i][j]==inf)
				printf("   00");//表示无穷大 
			else
				printf("%5d",G.arcs[i][j]);
		}
		printf("\n");
	}
}

int VexDeg(MGraph G,int vex,vector<int> &vec)//求无向图（网）顶点的度和邻接点 
{
	int cnt=0;
	if(G.Graphkind==3)//无向图 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]!=0)
		{ 
			vec.push_back(i);
			cnt++;
		}
	if(G.Graphkind==4)//无向网 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]!=inf)
		{
			vec.push_back(i);
			cnt++;
		}
	return cnt;
}

int VexIndeg(MGraph G,int vex)//求有向图（网）顶点的入度 
{
	int cnt=0;
	if(G.Graphkind==1)//有向图 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[i][vex]!=0)
			cnt++;
	if(G.Graphkind==2)//有向网 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[i][vex]!=inf)
			cnt++;
	return cnt;
}

int VexOutdeg(MGraph G,int vex)//求有向图（网）顶点的出度 
{
	int cnt=0;
	if(G.Graphkind==1)//有向图 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]!=0)
			cnt++;
	if(G.Graphkind==2)//有向网 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]!=inf)
			cnt++;
	return cnt;
}

int vis[maxn],dis[maxn];
void DFSGraph(MGraph G,int vex)//从顶点vex开始深度优先遍历无向图G 
{
	cout<<vex<<" ";
	vis[vex]=1;
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]==1&&vis[i]==0)
			DFSGraph(G,i);
}

void BFSGraph(MGraph G)//从顶点1开始广度优先遍历无向图G 
{
	queue<int> que;
	for(int i=1;i<=G.vexnum;i++)
		if(vis[i]==0)
		{
			vis[i]=1;
			cout<<i<<" ";
			while(!que.empty())
			{
				que.pop();
				for(int j=1;j<=G.vexnum;j++)
					if(G.arcs[i][j]==1&&vis[j]==0)
					{
						vis[j]=1;
						cout<<j<<" ";
						que.push(j);
					}
			}
		}
}

//求最小生成树 
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn];//数组u v w分别为边的顶点和权值，p为并查集父节点，r为边的编号 
bool cmp(const int i,const int j)
{
	return w[i]<w[j];
}
int find(int x)//并查集操作 
{
	return p[x]==x ? x:p[x]=find(p[x]);
}
int Kruskal(MGraph G)//Kruskal算法求最小生成树 
{
	int cnt=0,ans=0,n=G.vexnum,m=G.arcnum;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(G.arcs[i][j]<inf)
			{
				u[++cnt]=i;
				v[cnt]=j;
				w[cnt]=G.arcs[i][j];
			}
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
		r[i]=i;
	sort(r+1,r+m+1,cmp);//按边的权值排序 
	for(int i=1;i<=m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)
		{
			cout<<u[e]<<" "<<v[e]<<endl;//输出加入的边 
			p[x]=y;//合并 
			ans+=w[e];
		}
	}
	return ans;
}

int Prim(MGraph G)//Prim算法求最小生成树 
{
	memset(vis,0,sizeof(vis));
	int n=G.vexnum;
	for(int i=1;i<=n;i++)
		dis[i]=G.arcs[1][i];
	dis[1]=0;vis[1]=1;
	for(int i=1;i<n;i++)
	{
		int k=0,minn=inf;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]<minn)
			{
				minn=dis[j];
				k=j;
			}
		vis[k]=1;
		cout<<k<<" ";//输出加入的顶点 
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>G.arcs[k][j])
				dis[j]=G.arcs[k][j];
	}
	cout<<endl; 
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=dis[i];
	return ans;
}

//求最短路径 
int Dijkstra(MGraph G,int u,int v)//Dijkstra算法求单源最短路 
{
	memset(vis,0,sizeof(vis));
	int n=G.vexnum;
	for(int i=1;i<=n;i++)
		dis[i]=G.arcs[u][i];//以u为原点 
	dis[u]=0;vis[u]=1;
	for(int i=1;i<n;i++)
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
	}
	return dis[v];
}

int Floyd(MGraph G,int u,int v)//Floyd算法求任意两点最短路 
{
	for(int k=1;k<=G.vexnum;k++)
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		if(G.arcs[i][k]+G.arcs[k][j]<G.arcs[i][j])
			G.arcs[i][j]=G.arcs[i][k]+G.arcs[k][j];
	return G.arcs[u][v];//顶点u到v的最短路径长度 
}


int main()
{
	MGraph G;
	int n; 
	cin>>n;//测试数据编号 
	
	//数据测试1：无向图 深度、广度优先遍历 
	if(n==1)
	{
		CreateGraph(G);//构造图G 
		memset(vis,0,sizeof(vis));
		cout<<"图G的深度优先遍历顶点访问序列为：";
		DFSGraph(G,1);//从顶点1开始深度优先遍历图G 
		cout<<endl;
		memset(vis,0,sizeof(vis));
		cout<<"图G的广度优先遍历顶点访问序列为：";
		BFSGraph(G);//广度优先遍历图G 
		cout<<endl; 
	}
	
	//数据测试2：无向网 最小生成树、最短路径 
	if(n==2)
	{
		CreateGraph(G);//构造图G 
		vector<int> vec;
		cout<<"顶点3的度为："<<VexDeg(G,3,vec)<<endl;
		cout<<"顶点3的邻接点为：";
		for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		cout<<endl;
		PrintGraph(G);//打印图G的邻接矩阵 
		
		cout<<"用Prim算法求图G的最小生成树："<<endl;
		cout<<"每次加入的顶点为："<<endl;
		cout<<"最小生成树代价为："<<Prim(G)<<endl;
		cout<<"用Kruskal算法求图G的最小生成树："<<endl;
		cout<<"每次加入的边为："<<endl; 
		cout<<"最小生成树代价为："<<Kruskal(G)<<endl;
		cout<<"用Dijkstra算法求得顶点1和5之间的最短路径长度为："<<Dijkstra(G,1,5)<<endl;
		cout<<"用Floyd算法求得顶点1和5之间的最短路径长度为："<<Floyd(G,1,5)<<endl;
	}
	
	return 0;
}
/*
	无向图 深度、广度优先遍历 测试样例：
	8
	9
	1 2
	1 3
	2 4
	2 5
	3 6
	3 7
	4 8
	5 8
	6 7
	
	无向网 最小生成树、最短路径 测试样例：
	6
	10
	1 2 6
	1 3 1
	1 4 5
	2 3 5
	2 5 3
	3 4 5
	3 5 6
	3 6 4
	4 6 2
	5 6 6
*/ 
