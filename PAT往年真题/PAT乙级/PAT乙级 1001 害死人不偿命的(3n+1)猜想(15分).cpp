#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	while(n!=1)
	{
		if(n%2==1)
			n=(3*n+1)/2;
		else
			n=n/2;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
