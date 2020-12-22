#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b)
{
	return b==0 ? a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return a*b/gcd(a,b);
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<lcm(a,b)<<endl; 
	return 0;
}
