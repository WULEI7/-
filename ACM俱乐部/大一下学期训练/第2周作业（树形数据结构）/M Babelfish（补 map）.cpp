#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	map<string,string> mp;
	string a,b,s;
	while(1)
	{
		getline(cin,s);
		if(s.length()==0) break;
		stringstream ss;
		ss<<s;
		ss>>a>>b;
		mp[b]=a;
	}
	while(cin>>s)
	{
		if(mp.count(s))
			cout<<mp[s]<<endl;
		else
			cout<<"eh"<<endl;
	}
	return 0;
}
