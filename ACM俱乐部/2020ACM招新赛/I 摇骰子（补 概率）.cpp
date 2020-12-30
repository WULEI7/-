#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	return b==0 ? a:gcd(b,a%b);
}
int main()
{
	ll n,t,x;
	scanf("%lld %lld",&n,&t);
	while(t--)
	{
		scanf("%lld",&x);
		if(x==1||x>2*n)
		{
			printf("0\n");
			continue;
		}
		ll fm=n*n;
		ll fz=n-abs(n+1-x);
		ll g=gcd(fz,fm);
		fz/=g;fm/=g;
		printf("%lld/%lld\n",fz,fm);
	}
	return 0;
}
