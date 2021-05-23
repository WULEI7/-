#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,a,b,c,d;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		if(4*b*b-12*a*c>0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
