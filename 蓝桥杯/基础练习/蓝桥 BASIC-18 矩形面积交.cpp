#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	double x[4],y[4];
	cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
	if(max(y[2],y[3])<=min(y[0],y[1])||min(y[2],y[3])>=max(y[0],y[1])||max(x[2],x[3])<=min(x[0],x[1])||min(x[2],x[3])>=max(x[0],x[1]))
		cout<<"0.00"<<endl;
	else
	{
		sort(x,x+4);
		sort(y,y+4);
		double l=x[2]-x[1];
		double w=y[2]-y[1];
		cout<<fixed<<setprecision(2)<<l*w<<endl;
	}
	return 0;
}
