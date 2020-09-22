#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 99999999
using namespace std;
int n,m,vis[205],dis[205],map[205][205];
void dijkstra(int x)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=map[x][i];//��xΪԭ�� 
	for(int i=1;i<=n;i++)
	{
		int k=0,minn=inf;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]<minn)
			{
				minn=dis[j];
				k=j;
			}
		if(k==0) break;//���д�ϣ���Ϊ�е���Ŀ�����߲�ͨ 
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>dis[k]+map[k][j])
				dis[j]=dis[k]+map[k][j];
	}
}//���·�����⣬dijkstra�㷨 
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)//��ô�0��ʼ��ʼ������Ϊ�е���Ŀ�����߲�ͨ 
	{
		if(i==j)
			map[i][j]=0;
		else
			map[i][j]=inf;
	}//ͼ�ĳ�ʼ�� 
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	{
		
		scanf("%d",&m);
		map[i][j]=m;
	}
	dijkstra(1);//��1����� 
	printf("%d\n",dis[n]);
	return 0;
}
