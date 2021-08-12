#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long d[100005];
	d[0]=0,d[1]=0,d[2]=1;
	for(int i=3;i<=100000;i++)
		d[i]=(i-1)*(d[i-1]+d[i-2])%19260817;
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",d[n]);
	}
	return 0;
}
