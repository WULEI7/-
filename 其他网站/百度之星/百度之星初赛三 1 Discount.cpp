#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		double a,b,c=0,t;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%lf%lf",&a,&b);
			t=(1-b)/(a+1-b);
			if(t>c)
				c=t;
		}
		printf("%.5f\n",c);
	}
	return 0;
}
