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
	int Graphkind;//ͼ�����ࣨ1Ϊ��������2Ϊ�������� 
}MGraph;//ͼ 

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
	cout<<"������ͼ�����ࣨ1Ϊ��������2Ϊ����������";
	cin>>G.Graphkind;
	switch(G.Graphkind)
	{
		case 1:CreateDN(G);break;
		case 2:CreateUDN(G);break;
		default:
			cout<<"����ʧ�ܣ�"<<endl;
			return; 
	}
}

void PrintGraph(MGraph G)//��ӡͼG���ڽӾ��� 
{
	for(int i=1;i<=G.vexnum;i++)
	{
		for(int j=1;j<=G.vexnum;j++)
		{
			if(G.arcs[i][j]==inf)
				printf("  INF");//��ʾ����� 
			else
				printf("%5d",G.arcs[i][j]);
		}
		printf("\n");
	}
}

//�����·�� 
int vis[maxn],dis[maxn];
void Dijkstra(MGraph G,int u)//Dijkstra�㷨��Դ���· 
{
	memset(vis,0,sizeof(vis));
	int n=G.vexnum;
	for(int i=1;i<=n;i++)
		dis[i]=G.arcs[u][i];//��uΪԭ�� 
	dis[u]=0;vis[u]=1;
	for(int i=1;i<n;i++)//ѡ��ʣ�µ�n-1������ 
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
		//���forѭ��ÿһ�ֺ��״̬ 
		cout<<"��"<<i<<"��ѡ�еĶ���Ϊ��"<<k<<endl;
		cout<<"��"<<i<<"�ֺ�dis�����ֵΪ��";
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

void Floyd(MGraph &G)//Floyd�㷨�������������· 
{
	int n=G.vexnum;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(G.arcs[i][k]+G.arcs[k][j]<G.arcs[i][j])
				G.arcs[i][j]=G.arcs[i][k]+G.arcs[k][j];
		//���forѭ��ÿһ�ֺ��״̬ 
		cout<<"���Զ���"<<k<<"��G���ڽӾ���Ϊ��"<<endl;
		PrintGraph(G);
	}
}

int main()
{
	MGraph G;
	CreateGraph(G);//����ͼG 
	cout<<endl;
	cout<<"��ӡͼG���ڽӾ���Ϊ��"<<endl;
	PrintGraph(G);//��ӡͼG���ڽӾ��� 
	cout<<endl;
	cout<<"Dijkstra�㷨��"<<endl;
	Dijkstra(G,1);
	cout<<"��Dijkstra�㷨��ö���1��5֮������·������Ϊ��"<<dis[5]<<endl;
	cout<<endl;
	cout<<"Floyd�㷨��"<<endl;
	Floyd(G);
	cout<<"��Floyd�㷨��ö���1��5֮������·������Ϊ��"<<G.arcs[1][5]<<endl;
	return 0;
}
/*
	�������ݣ�
	
	������ 
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
	
	������ 
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
