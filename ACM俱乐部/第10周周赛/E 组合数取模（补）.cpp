#include <iostream>
#include <cmath>
using namespace std;
const long long p=998244353;//对p取模 

long long pow(long long x,long long y)
{
    if (y==0) return 1;
    long long z=pow(x,y/2)%p;
    if (y%2==0) return z*z%p;
    return z*z%p*x%p;
}
long long ni(long long x)
{
    return pow(x,p-2);
}
long long Com(int n,int m)
{
    if (m==0) return 1%p;
    if (n==0) return 0;
    if (n>=p||m>=p) return Com(n/p,m/p)*Com(n%p,m%p)%p;//卢卡斯定理
    long long x=1,y=1;
    for(int i=n;i>=n-m+1;i--)
		x=x*i%p;
    for(int i=1;i<=m;i++)
		y=y*i%p;
    return x*ni(y)%p;
}//组合数取模 

int main()
{
	long long n,m,k,ans;
	cin>>n>>m>>k;
	ans=m;
	for(int i=1;i<=k;i++)
	{
		ans*=m-1;
		ans%=998244353;
	}
	ans*=Com(n-1,k);
	ans%=998244353;
	cout<<ans<<endl;
}
