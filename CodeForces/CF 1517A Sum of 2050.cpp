#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%2050!=0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		long long temp=2050*pow(10,15);
		int ans=0;
		while(n>0)
		{
			long long num=n/temp;
			n-=num*temp;
			ans+=num;
			temp/=10;
		}
		cout<<ans<<endl;
	}
	return 0;
}
