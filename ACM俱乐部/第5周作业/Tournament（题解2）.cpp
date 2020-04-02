#include <iostream>
#include<cstdio>
using namespace std;
int n,k;
int dp[1100][1100];
void dfs(int l,int r,int cur)
{
    if(cur==1)
    {
        for(int i=1;i<=n;i++)
            dp[cur][i]=i;
        return;
    }
    dfs(l,(l+r)/2,cur/2);
    for(int i=cur/2+1;i<=cur;i++)
    {
        for(int j=1;j<=n;j+=cur)
        {
            int k=j+cur-1;
            for(int mm=j;mm<j+cur;mm++)
            {
                dp[i][mm]=dp[cur/2-(i-cur/2-1)][k-(mm-j)];
            }

        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        int m=n;
        int flag=1;
        int cnt=0;
        while((m&1) != 1)
        {
            cnt++;
            m>>=1;
        }
        if(flag&&(1<<cnt)-1<k) flag=0;
        if(!flag) printf("Impossible\n");
        else
        {
            dfs(1,n,(1<<cnt));
            for(int i=2;i<=k+1;i++)
            {
                for(int j=1;j<=n;j++)
                    printf("%d%c",dp[i][j]," \n"[j==n]);
            }
        }
    }
    return 0;
}
