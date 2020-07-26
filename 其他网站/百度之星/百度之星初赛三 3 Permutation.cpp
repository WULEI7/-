#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long a,b,n,s,ans;
		scanf("%d%d",&a,&b);
		s=2*a-3;
		if(a/2>b) n=b;
		else n=a/2;
		ans=n*s-2*n*(n-1);
		printf("%lld\n",ans);
	}
	return 0;
}
