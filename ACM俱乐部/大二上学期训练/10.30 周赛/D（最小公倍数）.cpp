#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b)
{
	return b==0 ? a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return a*b/gcd(a,b);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%2==0)
		{
			printf("%d %d\n",n/2,n/2);
			continue;
		}
		else
		{
			int t=1,s=sqrt(n);
			for(int i=2;i<=s;i++)
				if(n%i==0)
				{
					t=n/i;
					break;
				}
			printf("%d %d\n",t,n-t);
		}
	}
	return 0;
}
