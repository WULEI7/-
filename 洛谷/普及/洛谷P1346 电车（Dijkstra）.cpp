#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define inf 99999999
using namespace std;
int n,a,b,vis[105],dis[105],map[105][105];
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
		if(k==0) break;//�˾����Ҫ����Ϊ��������߲�ͨ 
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[j]>dis[k]+map[k][j])
				dis[j]=dis[k]+map[k][j];
	}
}//���·�����⣬dijkstra�㷨 
int main()
{
	int a,b,num,t;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)//������Ϊ�п����߲�ͨ����ô�0��ʼ��ʼ�� 
	{
		if(i==j)
			map[i][j]=0;
		else
			map[i][j]=inf;
	}//ͼ�ĳ�ʼ�� 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num);
		for(int j=1;j<=num;j++)
		{
			scanf("%d",&t);
			if(j==1)
				map[i][t]=0;
			else
				map[i][t]=1;
		}
	}
	dijkstra(a);//��a����� 
	if(dis[b]>=inf)//�п���û���ﵽb�� 
		printf("-1\n");
	else 
		printf("%d\n",dis[b]);
	return 0;
}
