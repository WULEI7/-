#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define inf 99999999
using namespace std;
int n,vis[105],dis[105],map[105][105],flag[105][105];
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
	int m,d,s,t,w,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)//��ô�0��ʼ��ʼ������Ϊ�е���Ŀ�����߲�ͨ 
	{
		if(i==j)
			map[i][j]=0;
		else
			map[i][j]=inf;
	}//ͼ�ĳ�ʼ�� 
	while(m--)
	{
		scanf("%d%d%d",&s,&t,&w);
		map[s][t]=map[t][s]=w;
	}
	scanf("%d",&d);
	while(d--)
	{
		scanf("%d%d",&s,&t);
		flag[s][t]=flag[t][s]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(flag[i][j]==0&&map[i][j]<inf)//ע��ϸ�ڣ� 
			map[i][j]=0;
	scanf("%d%d",&s,&t);
	dijkstra(s);//��s����� 
	printf("%d\n",dis[t]);
	return 0;
}
