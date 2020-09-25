#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long t,r,b,k,x,y;
	cin>>t;
	while(t--)
	{
		cin>>r>>b>>k;
		if(r<b)
		{
			x=r;
			y=b;
		}
		else
		{
			x=b;
			y=r;
		}
		if(x*k>=y)
			printf("OBEY\n");
		else
			printf("REBEL\n");
	}
	return 0;
}
