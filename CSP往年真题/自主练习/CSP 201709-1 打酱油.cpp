#include <cstdio>
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	ans+=(n/50)*7;
	n%=50;
	ans+=(n/30)*4;
	n%=30;
	ans+=n/10;
	printf("%d\n",ans);
	return 0;
}
