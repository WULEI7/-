#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	double a,b,c;
	cin>>a>>b;
	c=sqrt(a*a+b*b);
	printf("%.9f\n",a+b-c);
	return 0;
}
