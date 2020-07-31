#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
//min tree--maxn
const int maxn=5*1e5+10;
int f[maxn];
struct edge{
    int u,v,w;
    bool operator <(const edge &u)const
    {
        return w<u.w;
    }
}edge[2*maxn];
int tot;
void addedge(int u,int v,int w)
{
    edge[tot].u=u;
    edge[tot].v=v;
    edge[tot++].w=w;
}
int find(int x)
{
    return  f[x]==-1?x:f[x]=find(f[x]);
}
int kruskal(int n)
{
    memset(f,-1,sizeof(f));
    sort(edge,edge+tot);
    int cnt=0,ans=-1;
    for(int i=0;i<tot;i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        int w=edge[i].w;
        int t1=find(u);
        int t2=find(v);
        if(t1!=t2)
        {
            //ans+=w;
            f[t1]=t2;
            ans=max(w,ans);
            cnt++;
        }
        if(cnt==n-1) break;
    }
    return ans;
}
int main()
{
    int n,m,root;
    int u,v,w;
    tot=0;
    //freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&root);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    printf("%d\n",kruskal(n));
    return 0;
}

