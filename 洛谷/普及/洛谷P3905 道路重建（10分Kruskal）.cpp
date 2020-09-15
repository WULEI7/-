#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=10005;
using namespace std;
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn],flag[maxn];
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
	int n,m,d,s,t,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;//���鼯��ʼ�� 
	for(int i=0;i<m;i++)
		r[i]=i;//�ߵ���� 
	for(int i=0;i<m;i++)
		cin>>u[i]>>v[i]>>w[i];
	cin>>d;
	for(int i=0;i<d;i++)
	{
		int a,b;
		cin>>a>>b;
		for(int i=0;i<m;i++)
			if(u[i]==a&&v[i]==b||u[i]==b&&v[i]==a)
				flag[i]=1;
	}//��Ǳ��ƻ��ĵ�· 
	for(int i=0;i<m;i++)
		if(flag[i]==0)
			w[i]=0;//δ���ƻ��ĵ�·Ȩֵ��Ϊ0 
	sort(r,r+m,cmp);
	cin>>s>>t;
	for(int i=0;i<m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)
		{
			p[x]=p[y];
			ans+=w[e];//�ص㣡����ⲻ����Kruskal����Ϊ���ﲻ�������߳�����������·������ 
		}
		if(find(s)==find(t)) break;//��s��t��ͨʱ���� 
	}
	cout<<ans<<endl;
	return 0;
}
