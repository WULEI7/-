#include<algorithm>  
#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<queue>  
#define N 205  
#define INF 0x3f3f3f3f  
typedef long long LL;  
using namespace std;  
  
struct P{  
    int x,y;  
}p[205];  
  
int n,m,k,r;  
int d[205][205];  
bool vis[205][205],Map[205][205];  
  
void spfa()  
{  
    queue<P> q;  
    memset(vis,0,sizeof(vis));  
    memset(d,INF,sizeof(d));  
    d[0][0]=0;  
    vis[0][0]=1;  
    P s,tem;  
    s.x=s.y=0;  
    q.push(s);  
    while(!q.empty())  
    {  
        s=q.front();  
        q.pop();  
        vis[s.x][s.y]=0;  
        for(int i=0;i<n+m;++i)  
            if(Map[s.x][i])  
            {  
                tem.x=i;  
                tem.y=s.y;  
                if(i>=n) ++tem.y;  
                if(tem.y<=k&&d[tem.x][tem.y]>d[s.x][s.y]+1)  
                {  
                    d[tem.x][tem.y]=d[s.x][s.y]+1;  
                    if(!vis[tem.x][tem.y])  
                    {  
                        vis[tem.x][tem.y]=1;  
                        q.push(tem);  
                    }  
                }  
            }  
    }  
    int ans=INF;  
    for(int i=0;i<=k;i++) ans=min(ans,d[1][i]);  
    printf("%d\n",ans-1);  
}  
  
int main()  
{  
    int i,j;  
    cin>>n>>m>>k>>r;  
    for(i=0;i<n+m;++i) scanf("%d%d",&p[i].x,&p[i].y);  
    memset(Map,0,sizeof(Map));  
    for(i=0;i<n+m;++i)  
        for(j=i+1;j<n+m;++j)  
            if(LL(p[i].x-p[j].x)*(p[i].x-p[j].x)+LL(p[i].y-p[j].y)*(p[i].y-p[j].y)<=LL(r)*r) Map[i][j]=Map[j][i]=1;  
  
    spfa();  
    return 0;  
}  

