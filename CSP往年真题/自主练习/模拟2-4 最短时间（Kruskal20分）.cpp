#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=100005;
using namespace std;
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn];
int cmp(const int i,const int j)
{
	return w[i]<w[j];
}
int find(int x)
{
	return p[x]==x ? x:p[x]=find(p[x]);
}//���鼯 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		p[i]=i;//���ڲ��鼯 
	for(int i=0;i<m;i++)
		r[i]=i;//�ߵı�� 
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>u[i]>>v[i]>>b;
		if(a==0)//�ĳ��� 
		{
			if(u[i]==1||v[i]==1)
				w[i]=b;
			else
				w[i]=1+b;
		}
		else if(a==1)//������ 
		{
			if(u[i]==1||v[i]==1)
				w[i]=2*b;
			else
				w[i]=2+2*b;
		}
	}
	sort(r,r+m,cmp);
	for(int i=0;i<m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)
		{
			p[x]=y;
			ans+=w[e];
		}
		if(find(1)==find(n)) break;//��1��n��ͨʱ���� 
	}
	cout<<ans<<endl;
	return 0;
}
