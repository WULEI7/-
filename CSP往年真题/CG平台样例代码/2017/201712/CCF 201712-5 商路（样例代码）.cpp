#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
#include<queue>  
using namespace std;  
typedef long long ll;  
const ll MOD=1e18;  
const int N=1e5+10;  
ll v[N],f[N],u[N],s[N];  
ll ans[N];  
int vis[N];  
void init()  
{  
    memset(ans,0,sizeof(ans));  
    memset(vis,0,sizeof(vis));  
}  
int main()  
{  
    int T,n;  
    scanf("%d",&T);  
    while(T--)  
    {  
        init(); //初始化   
        scanf("%d",&n);  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d%d%d%d",&u[i],&s[i],&v[i],&f[i]);  
            vis[u[i]]++; //vis数组保存这个点的直接下级数量   
        }  
        int q[N],q0=0,q1=0;  
        for(int i=1;i<=n;i++) //这里类似拓扑排序，直接下级数量为零入队   
        if(!vis[i]) q[q1++]=i;  
        while(q0<q1)  
        {  
            int k=q[q0++];  
            int t=u[k],d=s[k];  
            vis[t]--;  
            if(!vis[t]) q[q1++]=t; //直接下级全都处理过了，入队   
            while(t) //寻找所有上级，计算上级城市到这里的获利，取最大值   
            {  
                ans[t]=max(ans[t],(ans[k]+v[t]-(f[t]-d)*(f[t]-d))); //ans里保存了以这个城市为开头的商路最大价值   
                d+=s[t];  
                t=u[t];  
            }  
        }  
        ll sum=0;  
        for(int i=1;i<=n;i++) sum=(sum+ans[i])%MOD; //计算总价值   
        printf("%lld\n",sum);  
    }  
    return 0;  
}  

