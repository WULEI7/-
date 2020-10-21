#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=250005;
using namespace std;
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn],rela[505][505];
int cmp(const int i,const int j)
{
	return w[i]<w[j];
}//边权比较 
int find(int x)
{
	return p[x]==x ? x:p[x]=find(p[x]);
}//并查集 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k,temp=0,flag=1,ans=0;
	cin>>k>>n;
	m=n*n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		cin>>rela[i][j];
	for(int i=1;i<=n;i++)
		p[i]=i;//并查集初始化 
	for(int i=0;i<m;i++)
		r[i]=i;//边的序号 
	int t=0;//边的数量 
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
	{
		if(i==j||rela[i][j]==0) continue;
		u[t]=i;v[t]=j;w[t]=rela[i][j];
		t++;
	}
	sort(r,r+t,cmp);
	for(int i=0;i<t;i++)
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
		if(temp==n-1)
			break;
	}
	ans+=k;
	if(ans<n*k)
		cout<<ans<<endl;
	else
		cout<<n*k<<endl;
	return 0;
}
