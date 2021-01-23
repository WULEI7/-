#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		int pos=s.find("accept",0);
		if(pos==-1)
			cout<<"Impossible"<<endl;
		else
			cout<<"fun"<<endl;
	}
	return 0;
}
