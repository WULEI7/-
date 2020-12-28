#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=100005;
using namespace std;
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn];
//u v w数组分别表示边的起点 终点和权值
//p数组表示结点的父结点 r数组表示边的编号 
int cmp(const int i,const int j)
{
	return w[i]<w[j];
}//边权值比较 
int find(int x)
{
	return p[x]==x ? x:p[x]=find(p[x]);
}//并查集操作 
int main()
{
	int n,m,root,ans=0;
	cin>>n>>m>>root;
	for(int i=1;i<=n;i++)
		p[i]=i;//父结点初始化 
	for(int i=0;i<m;i++)
		r[i]=i;//边的编号 
	for(int i=0;i<m;i++)
		cin>>u[i]>>v[i]>>w[i];//输入数据 
	sort(r,r+m,cmp);//边的排序 
	for(int i=0;i<m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)//起点和终点不在同一集合中 
		{
			p[x]=y;
			if(w[e]>ans)
				ans=w[e];
		}//更新ans的值 
	}
	cout<<ans<<endl;//输出结果 
	return 0;
}
