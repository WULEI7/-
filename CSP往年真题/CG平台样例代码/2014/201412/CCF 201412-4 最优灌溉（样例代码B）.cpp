#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1000+10;//点数
const int MAXM=200000+10;//边数,无向图要*2 
int UF[MAXN];
struct Edge
{
	int u,v,w;
}edge[MAXM];
int tol; //初始化为0 
void addedge(int u,int v,int w)
{
	edge[tol].u=u;
	edge[tol].v=v;
	edge[tol++].w=w;
} 
bool cmp(Edge a,Edge b) 
{
	return a.w<b.w; 
}
int find(int x) 
{  
	if(UF[x]==-1) return x;  
	else return UF[x]=find(UF[x]);
}
int Kruskal(int n)
{
	memset(UF,-1,sizeof(UF));
	sort(edge,edge+tol,cmp);
	int cnt=0;
	int ans=0;
	for(int i=0;i<tol;i++)
	{
		int u=edge[i].u;   
		int v=edge[i].v;   
		int w=edge[i].w; 
		int t1=find(u);
		int t2=find(v);
		if(t1!=t2)
		{
			UF[t1]=t2;
			ans+=w;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	if(cnt<n-1) return -1;
	return ans;
}
int main()
{
    tol=0;
    int n,m,a,b,c;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
    	scanf("%d%d%d",&a,&b,&c);
    	addedge(a,b,c);
    	addedge(b,a,c);
    }
    printf("%d\n",Kruskal(n));
    return 0;
}
