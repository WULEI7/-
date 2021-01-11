#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a,b,ans=0;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		ans+=a*b;
	}
	if(ans<0) ans=0;
	cout<<ans<<endl;
	return 0;
}
