#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		if(n<=2)
			cout<<"1"<<endl;
		else
		{
			if((n-2)%x==0)
				cout<<(n-2)/x+1<<endl;
			else
				cout<<(n-2)/x+2<<endl;
		}
	}
	return 0;
}
