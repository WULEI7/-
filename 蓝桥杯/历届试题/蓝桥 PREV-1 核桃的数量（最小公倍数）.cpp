#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	int a,b,c,ans;
	cin>>a>>b>>c;
	ans=lcm(a,b);
	ans=lcm(ans,c);
	cout<<ans<<endl;
	return 0;
}
