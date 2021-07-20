#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	double r,a,b,h,x,s,ans;
	cin>>r>>a>>b>>h;
	if(2*r<b)
		printf("Drop\n");
	else
	{
		x=b*h/(a-b);
		s=sqrt((a/2)*(a/2)+(x+h)*(x+h));
		ans=2*r*s/a-x;
		printf("Stuck\n%.10f\n",ans);
	}
	return 0;
}
