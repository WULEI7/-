#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,l,r;
	cin>>n>>l>>r;
	if(l==r)
	{
		if((n-1)%l==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	else
	{
		if(l<=n-1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
