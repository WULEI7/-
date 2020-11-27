#include <cstdio>
#include <cmath>
#define pi acos(-1.0)
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double n,ans;
		scanf("%lf",&n);
		ans=1/tan(pi/n/2);
		printf("%.9f\n",ans);
	}
	return 0;
}
