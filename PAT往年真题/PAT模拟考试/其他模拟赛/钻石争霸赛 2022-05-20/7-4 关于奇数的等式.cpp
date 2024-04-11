#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(long long x=1;x<=m;x+=2)
	for(long long y=x+2;y<=m;y+=2)
	for(long long z=y+2;z<=m;z+=2)
	if(3*x*y*z==n*x*y+n*x*z+n*y*z)
	{
		printf("%lld %lld %lld",x,y,z);
		return 0;
	}
	printf("No solution in (3, %d].",m);
	return 0;
}
