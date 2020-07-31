#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int N=5e4+10;
const int K=1e2+10;
int n,m,k,u,v,w;
int num[N];
ll dp[N][K],tmp[K];
vector<P>E[N];
bool ok[N];
void dfs(int u,int fa)
{
    dp[u][0]=0;
    if(ok[u])
    {
        num[u]=1;
        dp[u][1]=0;
    }
    for(int i=0;i<E[u].size();++i)
    {
        int v=E[u][i].fi,w=E[u][i].se;
        if(v==fa)continue;
        dfs(v,u);
        int sum=min(k,num[u]+num[v]),mn=min(k,num[u]);
        for(int p=0;p<=sum;++p)
        tmp[p]=dp[u][p];
        for(int p=0;p<=mn;++p)//其余子树p个
        for(int q=0;p+q<=sum;++q)//当前子树q个
        tmp[p+q]=min(tmp[p+q],dp[u][p]+dp[v][q]+1ll*q*(k-q)*w);
        for(int p=0;p<=sum;++p)
        dp[u][p]=min(dp[u][p],tmp[p]);
        num[u]+=num[v];
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(dp,INF,sizeof dp);
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&v);
        ok[v]=1;
    }
    for(int i=2;i<=n;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        E[u].pb(P(v,w));
        E[v].pb(P(u,w));
    }
    dfs(1,-1);
    //for(int i=1;i<=n;++i)
    //for(int j=1;j<=k;++j)
    //printf("dp[%d][%d]:%lld\n",i,j,dp[i][j]);
    printf("%lld\n",dp[1][k]);
    return 0;
}
/*
5 3 2
1 3 5
1 2 4
1 3 5
1 4 3
4 5 1

11 6 2
2 5 7 8 9 10
1 2 2
1 3 4
2 4 3
2 5 6
3 6 8
3 7 11
4 8 9
6 9 2
6 10 1
7 11 4
*/

