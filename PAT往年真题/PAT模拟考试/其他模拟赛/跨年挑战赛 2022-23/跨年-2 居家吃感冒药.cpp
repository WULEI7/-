#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	char a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if(a=='0')
			cout<<1<<endl;
		else
		{
			if(b=='1')
				cout<<2<<endl;
			else
				cout<<3<<endl;
		}
	}
	return 0;
}
