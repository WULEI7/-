#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long a,long long b)
{
	return b==0 ? a:gcd(b,a%b);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long a,b;
	cin>>a>>b;
	if(a==b)
		printf("%lld\n",a);
	else
	{
		if(a>b)
		{
			a=a^b;
			b=a^b;
			a=a^b;
		}
		long long g;
		g=gcd(a,b);
		a/=g;
		b/=g;
		if((b-a)%2==1)
			printf("0\n");
		else
			printf("%lld\n",g);
	}
	return 0;
}
