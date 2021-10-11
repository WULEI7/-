#include <iostream>
#include <cstdio>
using namespace std;
int t;
double a,b,c,x0,x1,y0,y1,y2;
double y(double x)
{
	return a*x*x+b*x+c;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>x0>>x1>>y0>>y1>>y2;
		if(y(x0)>y0&&y(x1)<=y2&&y(x1)!=y0&&y(2*x1-x0)<y0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
