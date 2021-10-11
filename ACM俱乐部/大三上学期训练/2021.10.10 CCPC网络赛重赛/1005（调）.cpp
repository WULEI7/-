#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int N = 1e5+5;
ll a[N]={0};
ll sum[N]={0};
vector<ll> v[N];
int cnt=0;
map<ll,ll> mp;
map<ll,ll> minn;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n, m;
        scanf("%lld %lld",&n,&m);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
            sum[i] = sum[i-1]+a[i];
            if(minn[sum[i]]==0)
            {
                minn[sum[i]] = i;
            }
        }
        ll k = sum[n];
        for(int i=1;i<=n;++i)
        {

            ll num;
            if(k)
            {
                num = (sum[i]%k+k)%k;
            }
            else
            {
                num = sum[i];
            }
            if(!mp[num])
            {
                mp[num] = ++cnt;
            }
            ll id = mp[num];
            v[id].push_back(sum[i]);
        }
        for(int i=1;i<=cnt;++i)
        {
            sort(v[i].begin(),v[i].end());
        }
        ll x;
        for(int i=1;i<=m;++i)
        {
            scanf("%lld",&x);
            if(k==0)
            {
                if(x==0)
                {
                    printf("0\n");
                    continue;
                }
                if(minn[x])
                {
                    printf("%lld\n",minn[x]);
                }
                else
                {
                    printf("-1\n");
                }
            }
            else
            {
                if(x==0)
                {
                    printf("0\n");
                    continue;
                }
                ll num = (x%k+k)%k;
                ll id = mp[num];
                if(v[id].size()==0)
                {
                    printf("-1\n");
                }
                else
                {
                    ll pos = lower_bound(v[id].begin(),v[id].end(),x)-v[id].begin();
                    //printf("pos:%d\n",pos);
                    ll ans = 1e18;
                    if(pos<v[id].size());
                    {
                        ll time = (x-v[id][pos])/k;
                        if(time>=0)
                        {
                            ans = time*n+minn[v[id][pos]];
                        }
                    }
                    if(pos>0)
                    {
                        ll ans2 = 1e18;
                        ll time = (x-v[id][pos-1])/k;
                        if(time>=0)
                        {
                            ans2 = time*n+minn[v[id][pos-1]];
                        }
                        ans = min(ans2,ans);
                    }
                    if(ans==1e18)
                    {
                        ans = -1;
                    }
                    printf("%lld\n",ans);
                }
            }
        }

        for(int i=1;i<=cnt;++i)
        {
            v[i].clear();
        }
        cnt = 0;
    }
    return 0;
}
