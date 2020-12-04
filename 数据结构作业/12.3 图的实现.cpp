#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define maxn 105
#define inf 999999999//����� 
using namespace std;

typedef struct
{
	int arcs[maxn][maxn];//�ڽӾ��� 
	int vexnum;//�������������Ŵ�1��vexnum 
	int arcnum;//�ߣ������� 
	int Graphkind;//ͼ�����ࣨ1Ϊ����ͼ��2Ϊ��������3Ϊ����ͼ��4Ϊ�������� 
}MGraph;//ͼ 

void CreateDG(MGraph &G)//��������ͼG 
{
	cout<<"����������ͼG�Ķ�������";
	cin>>G.vexnum;
	cout<<"����������ͼG�Ļ�����";
	cin>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		G.arcs[i][j]=0;//ͼ�ĳ�ʼ�� 
	int u,v;
	cout<<"������ÿ�����ĳ�ʼ����ն˵㣺"<<endl;
	for(int i=1;i<=G.arcnum;i++)
	{
		cin>>u>>v;
		G.arcs[u][v]=1;
	}
}

void CreateDN(MGraph &G)//����������G 
{
	cout<<"������������G�Ķ�������";
	cin>>G.vexnum;
	cout<<"������������G�Ļ�����";
	cin>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		G.arcs[i][j]=inf;//���ĳ�ʼ�� 
	int u,v,w;
	cout<<"������ÿ�����ĳ�ʼ�㡢�ն˵��Ȩֵ��"<<endl;
	for(int i=1;i<=G.arcnum;i++)
	{
		cin>>u>>v>>w;
		G.arcs[u][v]=w;
	}
}

void CreateUDG(MGraph &G)//��������ͼG 
{
	cout<<"����������ͼG�Ķ�������";
	cin>>G.vexnum;
	cout<<"����������ͼG�ı�����";
	cin>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		G.arcs[i][j]=0;//ͼ�ĳ�ʼ�� 
	int u,v;
	cout<<"������ÿ���ߵ��������㣺"<<endl;
	for(int i=1;i<=G.arcnum;i++)
	{
		cin>>u>>v;
		G.arcs[u][v]=1;
		G.arcs[v][u]=1;
	}
}

void CreateUDN(MGraph &G)//����������G 
{
	cout<<"������������G�Ķ�������";
	cin>>G.vexnum;
	cout<<"������������G�ı�����";
	cin>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		G.arcs[i][j]=inf;//���ĳ�ʼ�� 
	int u,v,w;
	cout<<"������ÿ���ߵ����������Ȩֵ��"<<endl;
	for(int i=1;i<=G.arcnum;i++)
	{
		cin>>u>>v>>w;
		G.arcs[u][v]=w;
		G.arcs[v][u]=w;
	}
}

void CreateGraph(MGraph &G)//����ͼG 
{
	cout<<"������ͼ�����ࣨ1Ϊ����ͼ��2Ϊ��������3Ϊ����ͼ��4Ϊ����������";
	cin>>G.Graphkind;
	switch(G.Graphkind)
	{
		case 1:CreateDG(G);break; 
		case 2:CreateDN(G);break;
		case 3:CreateUDG(G);break;
		case 4:CreateUDN(G);break;
		default:
			cout<<"����ʧ�ܣ�"<<endl;
			return; 
	}
}

void PrintGraph(MGraph G)//��ӡͼG���ڽӾ��� 
{
	printf("ͼG���ڽӾ���Ϊ��\n");
	for(int i=1;i<=G.vexnum;i++)
	{
		for(int j=1;j<=G.vexnum;j++)
		{
			if(G.arcs[i][j]==inf)
				printf("   00");//��ʾ����� 
			else
				printf("%5d",G.arcs[i][j]);
		}
		printf("\n");
	}
}

int VexDeg(MGraph G,int vex,vector<int> &vec)//������ͼ����������ĶȺ��ڽӵ� 
{
	int cnt=0;
	if(G.Graphkind==3)//����ͼ 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]!=0)
		{ 
			vec.push_back(i);
			cnt++;
		}
	if(G.Graphkind==4)//������ 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]!=inf)
		{
			vec.push_back(i);
			cnt++;
		}
	return cnt;
}

int VexIndeg(MGraph G,int vex)//������ͼ�������������� 
{
	int cnt=0;
	if(G.Graphkind==1)//����ͼ 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[i][vex]!=0)
			cnt++;
	if(G.Graphkind==2)//������ 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[i][vex]!=inf)
			cnt++;
	return cnt;
}

int VexOutdeg(MGraph G,int vex)//������ͼ����������ĳ��� 
{
	int cnt=0;
	if(G.Graphkind==1)//����ͼ 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]!=0)
			cnt++;
	if(G.Graphkind==2)//������ 
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]!=inf)
			cnt++;
	return cnt;
}

int vis[maxn],dis[maxn];
void DFSGraph(MGraph G,int vex)//�Ӷ���vex��ʼ������ȱ�������ͼG 
{
	cout<<vex<<" ";
	vis[vex]=1;
	for(int i=1;i<=G.vexnum;i++)
		if(G.arcs[vex][i]==1&&vis[i]==0)
			DFSGraph(G,i);
}

void BFSGraph(MGraph G)//�Ӷ���1��ʼ������ȱ�������ͼG 
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

//����С������ 
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn];//����u v w�ֱ�Ϊ�ߵĶ����Ȩֵ��pΪ���鼯���ڵ㣬rΪ�ߵı�� 
bool cmp(const int i,const int j)
{
	return w[i]<w[j];
}
int find(int x)//���鼯���� 
{
	return p[x]==x ? x:p[x]=find(p[x]);
}
int Kruskal(MGraph G)//Kruskal�㷨����С������ 
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
	sort(r+1,r+m+1,cmp);//���ߵ�Ȩֵ���� 
	for(int i=1;i<=m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)
		{
			cout<<u[e]<<" "<<v[e]<<endl;//�������ı� 
			p[x]=y;//�ϲ� 
			ans+=w[e];
		}
	}
	return ans;
}

int Prim(MGraph G)//Prim�㷨����С������ 
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
		cout<<k<<" ";//�������Ķ��� 
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

//�����·�� 
int Dijkstra(MGraph G,int u,int v)//Dijkstra�㷨��Դ���· 
{
	memset(vis,0,sizeof(vis));
	int n=G.vexnum;
	for(int i=1;i<=n;i++)
		dis[i]=G.arcs[u][i];//��uΪԭ�� 
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
		if(k==0) break;//�˾����Ҫ����Ϊ�е�ͼ�����߲�ͨ 
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>dis[k]+G.arcs[k][j])
				dis[j]=dis[k]+G.arcs[k][j];
	}
	return dis[v];
}

int Floyd(MGraph G,int u,int v)//Floyd�㷨�������������· 
{
	for(int k=1;k<=G.vexnum;k++)
	for(int i=1;i<=G.vexnum;i++)
	for(int j=1;j<=G.vexnum;j++)
		if(G.arcs[i][k]+G.arcs[k][j]<G.arcs[i][j])
			G.arcs[i][j]=G.arcs[i][k]+G.arcs[k][j];
	return G.arcs[u][v];//����u��v�����·������ 
}


int main()
{
	MGraph G;
	int n; 
	cin>>n;//�������ݱ�� 
	
	//���ݲ���1������ͼ ��ȡ�������ȱ��� 
	if(n==1)
	{
		CreateGraph(G);//����ͼG 
		memset(vis,0,sizeof(vis));
		cout<<"ͼG��������ȱ��������������Ϊ��";
		DFSGraph(G,1);//�Ӷ���1��ʼ������ȱ���ͼG 
		cout<<endl;
		memset(vis,0,sizeof(vis));
		cout<<"ͼG�Ĺ�����ȱ��������������Ϊ��";
		BFSGraph(G);//������ȱ���ͼG 
		cout<<endl; 
	}
	
	//���ݲ���2�������� ��С�����������·�� 
	if(n==2)
	{
		CreateGraph(G);//����ͼG 
		vector<int> vec;
		cout<<"����3�Ķ�Ϊ��"<<VexDeg(G,3,vec)<<endl;
		cout<<"����3���ڽӵ�Ϊ��";
		for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		cout<<endl;
		PrintGraph(G);//��ӡͼG���ڽӾ��� 
		
		cout<<"��Prim�㷨��ͼG����С��������"<<endl;
		cout<<"ÿ�μ���Ķ���Ϊ��"<<endl;
		cout<<"��С����������Ϊ��"<<Prim(G)<<endl;
		cout<<"��Kruskal�㷨��ͼG����С��������"<<endl;
		cout<<"ÿ�μ���ı�Ϊ��"<<endl; 
		cout<<"��С����������Ϊ��"<<Kruskal(G)<<endl;
		cout<<"��Dijkstra�㷨��ö���1��5֮������·������Ϊ��"<<Dijkstra(G,1,5)<<endl;
		cout<<"��Floyd�㷨��ö���1��5֮������·������Ϊ��"<<Floyd(G,1,5)<<endl;
	}
	
	return 0;
}
/*
	����ͼ ��ȡ�������ȱ��� ����������
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
	
	������ ��С�����������·�� ����������
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
