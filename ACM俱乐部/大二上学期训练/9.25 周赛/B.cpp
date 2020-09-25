#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		if((1+i)*i/2-(n-i)==k)
		{
			printf("%d\n",n-i);
			break;
		}
	}
	return 0;
}
