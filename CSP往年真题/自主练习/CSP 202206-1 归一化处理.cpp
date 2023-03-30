#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	double a[1005],ave=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ave+=a[i];
	}
	ave/=n;
	double f,d=0;
	for(int i=0;i<n;i++)
		d+=(a[i]-ave)*(a[i]-ave);
	d/=n;
	for(int i=0;i<n;i++)
	{
		f=(a[i]-ave)/sqrt(d);
		cout<<fixed<<setprecision(16)<<f<<endl;
	}
	return 0;
}
