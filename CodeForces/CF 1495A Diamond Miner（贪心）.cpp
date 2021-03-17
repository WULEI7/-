#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double x[100005],y[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,px=0,py=0;
		double a,b,ans=0;
		scanf("%d",&n);
		for(int i=0;i<2*n;i++)
		{
			scanf("%lf%lf",&a,&b);
			if(a==0)
				y[py++]=fabs(b);
			if(b==0)
				x[px++]=fabs(a);
		}
		sort(x,x+n);
		sort(y,y+n);
		for(int i=0;i<n;i++)
			ans+=sqrt(x[i]*x[i]+y[i]*y[i]);
		printf("%.15f\n",ans);
	}
	return 0;
}
