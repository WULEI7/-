#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int n;
	string a,b;
	map<string,string> mp;
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		map<string,string>::iterator it;
		for(it=mp.begin();it!=mp.end();it++)
			if(it->second==a)
			{it->second=b;break;}
		if(it==mp.end())
			mp[a]=b;
	}
	cout<<mp.size()<<endl;
	map<string,string>::iterator i;
	for(i=mp.begin();i!=mp.end();i++)
		cout<<i->first<<" "<<i->second<<endl;
	return 0;
}
