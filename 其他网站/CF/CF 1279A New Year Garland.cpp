#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		if(a>b)
		{
			a=a^b;
			b=a^b;
			a=a^b;
		}
		if(a>c)
		{
			a=a^c;
			c=a^c;
			a=a^c;
		}
		if(b>c)
		{
			b=b^c;
			c=b^c;
			b=b^c;
		}
		if(c<=a+b+1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
