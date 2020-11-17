#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	long long n,r,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>r;
		if(n>r)
			ans=(1+r)*r/2;
		else
			ans=n*(n-1)/2+1;
		cout<<ans<<endl;
	}
	return 0;
}
