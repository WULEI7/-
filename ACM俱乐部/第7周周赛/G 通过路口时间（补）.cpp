#include <cstdio>
using namespace std;
struct car
{
	double len,s,v;
}c[100005];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<=n;i++)
			scanf("%lf",&c[i].len);
		for(int i=0;i<=n;i++)
			scanf("%lf",&c[i].s);
		for(int i=0;i<=n;i++)
			scanf("%lf",&c[i].v);
		double temp=0,ans=0;
		for(int i=0;i<=n;i++)
		{
			if(i!=0) temp+=c[i].len;
			double t=(c[i].s+temp)/c[i].v;
			if(t>ans) ans=t;
		}
		printf("%.10f\n",ans);
	}
	return 0;
}
