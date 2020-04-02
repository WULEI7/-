#include<bits/stdc++.h>
using namespace std;
int n,k;
int mp[1030][1030];
void t(int x)
{
    if(x==2)
    {
        mp[1][1]=1, mp[1][2]=2;
        mp[2][1]=2, mp[2][2]=1;
        return;
    }
    t(x/2);
    for(int i=1;i<=x/2;i++)
    {
        for(int j=1;j<=x/2;j++)
        {
            mp[i][j+x/2]=mp[i][j]+x/2;
            mp[i+x/2][j+x/2]=mp[i][j];
            mp[i+x/2][j]=mp[i][j]+x/2;
        }
    }
}
bool ok()
{
    for(int i=2;i<=k+1;i++) {
        for(int j=1;j<=n;j++) {
            if(mp[i][j]>n) return 0;
        }
    }
    return 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(n%2 || k>=n)
        {
            printf("Impossible\n");
            continue;
        }

        int N=1024;
        while((N/2)>=n) N/=2;

        t(N);

        if(!ok())
        {
            printf("Impossible\n");
            continue;
        }
        else
        {
            for(int i=2;i<=k+1;i++) {
                for(int j=1;j<=n;j++) {
                    printf("%d%c",mp[i][j],j==n?'':'\n');
                }
            }
        }
    }
}
