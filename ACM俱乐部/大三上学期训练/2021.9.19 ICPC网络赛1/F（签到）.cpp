#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		double a,b,c;
		cin>>a>>b>>c;
		double ans=0;
		if(b<=c)
			ans=2*a-c;
		else
			ans=2*sqrt(a*a+(b-c)*(b-c))-c;
		printf("Case #%d: %.2f\n",t,ans);
	}
	return 0;
}
