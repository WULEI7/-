#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		double a,b,c,x,ans=0;
		cin>>a>>b>>c>>x;
		ans+=sqrt(a*a+(b+c*2)*(b+c*2));
		ans+=sqrt(a*a+b*b)/100*x;
		ans+=sqrt((a/100*(100-x))*(a/100*(100-x))+(b/100*(100-x)+2*c)*(b/100*(100-x)+2*c));
		printf("%.9f\n",ans);
	}
	return 0;
}
