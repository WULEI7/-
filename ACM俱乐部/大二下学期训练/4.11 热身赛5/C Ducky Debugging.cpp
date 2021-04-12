#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	while(1)
	{
		getline(cin,s);
		if(s=="I quacked the code!") break;
		int len=s.length();
		if(s[len-1]=='.')
			cout<<"*Nod*"<<endl;
		if(s[len-1]=='?')
			cout<<"Quack!"<<endl;
	}
	return 0;
}
