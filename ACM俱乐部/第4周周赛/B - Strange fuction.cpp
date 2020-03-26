#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int t;
double y;
double f(double x)
{
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
double fd(double x)
{
	return 42*pow(x,6)+48*pow(x,5)+21*x*x+10*x-y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>y;
		double l=0,r=100,mid;
		while(r-l>1e-6)
		{
			mid=(l+r)/2;
			if(fd(mid)>0) r=mid;
			else l=mid;
		}
		cout<<fixed<<setprecision(4)<<f(mid)<<endl; 
	}
	return 0;
}
