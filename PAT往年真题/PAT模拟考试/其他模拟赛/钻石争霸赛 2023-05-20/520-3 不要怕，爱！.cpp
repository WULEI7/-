#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;
	cin>>n;
	while(n--)
	{
		cin>>t;
		if(t%2)
			cout<<"Love!"<<endl;
		else
			cout<<"!Love"<<endl;
	}
	return 0;
}
