#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		if(a>=n/2+1&&b>=n/2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
