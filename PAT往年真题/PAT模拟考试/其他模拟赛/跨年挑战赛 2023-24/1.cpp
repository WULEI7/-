#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int a=23,b=11,c=8;
	int ans=a*b*c;
	cout<<ans<<" is a special year!"<<endl;
	return 0;
}
