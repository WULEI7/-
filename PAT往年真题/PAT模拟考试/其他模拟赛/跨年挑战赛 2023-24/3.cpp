#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m,r;
	cin>>n>>m;
	while(m--)
	{
		cin>>r;
		if(r<=n/10)
			cout<<"1"<<endl;
		else if(r<=4*n/10)
			cout<<"2"<<endl;
		else
			cout<<"3"<<endl;
	}
	return 0;
}
