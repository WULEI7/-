#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
bool isprime(long long x)
{
	int flag=1;
	for(long long i=2;i*i<=x;i++)
		if(x%i==0) flag=0;
	return flag;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		if(n==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		long long s=sqrt(n);
		if(s*s==n&&isprime(s))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
