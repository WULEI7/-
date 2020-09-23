#include <iostream>
#include <cstdio>
#include <cmath> 
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,sum=0,cnt=0;
	while(cin>>n)
	{
		sum+=n;
		cnt++;
	}
	n=pow(2,cnt-1);
	printf("%lld\n",n*sum);
	return 0;
}
