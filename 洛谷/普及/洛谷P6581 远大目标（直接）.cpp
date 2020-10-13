#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	if(n<=0)
		cout<<"0"<<endl;
	else
	{
		unsigned long long m=n;
		cout<<2*m-1<<endl;
	}
	return 0;
}
