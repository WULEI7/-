#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int isprime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=4;;i++)
	{
		if(isprime(i)==1) continue;
		if(isprime(i+n)==0)
		{
			cout<<i+n<<" "<<i<<endl;
			break;
		}
	}
	return 0;
}
