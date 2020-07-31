#include<bits/stdc++.h>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int maxn=1050;
const ll mod=1e9+7;
ll f[maxn][10];
int main()
{
	IO;
	int n;cin>>n;
    f[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i][1]=1;
        f[i][2]=(f[i-1][2]*2+f[i-1][1])%mod;
        f[i][3]=(f[i-1][3]+f[i-1][1])%mod;
        f[i][4]=(f[i-1][4]*2+f[i-1][2])%mod;
        f[i][5]=(f[i-1][5]*2+f[i-1][2]+f[i-1][3])%mod;
        f[i][6]=(f[i-1][6]*2+f[i-1][4]+f[i-1][5])%mod;
    }
    cout<<f[n][6]<<"\n";	
    return 0;
}
