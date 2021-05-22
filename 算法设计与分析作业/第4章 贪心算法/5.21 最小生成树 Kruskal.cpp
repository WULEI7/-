#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m=0,ans=0,g[105][105];//������n������m 
int p[105];//���鼯�ĸ��ڵ� 

struct edge
{
	int u,v,w;//�ߵĶ����Ȩֵ 
}e[105];

bool cmp(edge a,edge b)//�ߵ�Ȩֵ�Ƚ� 
{
	return a.w<b.w;
}

int find(int x)//���鼯���� 
{
	return p[x]==x ? x:p[x]=find(p[x]);
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		cin>>g[i][j];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++) 
	{
		if(g[i][j]!=0)
		e[++m]={i,j,g[i][j]};
	}//����ÿ���� 
	sort(e+1,e+m+1,cmp);//���ߵ�Ȩֵ���� 
	for(int i=1;i<=n;i++)//���鼯���ڵ��ʼ�� 
		p[i]=i;
	for(int i=1;i<=m;i++)//���ο���ÿ���� 
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int x=find(u);
		int y=find(v);
		if(x!=y)
		{
			cout<<u<<" "<<v<<" "<<w<<endl;//�������ı� 
			p[x]=y;//�ϲ� 
			//ans+=w;
		}
	}
	//cout<<ans<<endl;
	return 0;
}
