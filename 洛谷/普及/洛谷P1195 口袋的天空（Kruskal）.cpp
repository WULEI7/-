#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=10005;
using namespace std;
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn];
int cmp(const int i,const int j)
{
	return w[i]<w[j];
}//��Ȩ�Ƚ� 
int find(int x)
{
	return p[x]==x ? x:p[x]=find(p[x]);
}//���鼯 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k,temp=0,flag=1,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		p[i]=i;//���鼯��ʼ�� 
	for(int i=0;i<m;i++)
		r[i]=i;//�ߵ���� 
	for(int i=0;i<m;i++)
		cin>>u[i]>>v[i]>>w[i];
	sort(r,r+m,cmp);
	for(int i=0;i<m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)
		{
			p[x]=p[y];
			ans+=w[e];
			temp++;
		}
		if(temp==n-k)
		{
			printf("%d\n",ans);
			flag=0;
			break;
		}
	}
	if(flag==1)
		printf("No Answer\n");
	return 0;
}
