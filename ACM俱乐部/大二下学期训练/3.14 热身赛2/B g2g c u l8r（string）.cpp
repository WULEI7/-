#include <iostream>
#include <cstdio>
#include <sstream>
#include <map>
using namespace std;
map<string,string> mp;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s,t,r;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		stringstream ss;
		getline(cin,s);
		ss<<s;
		ss>>t;
		getline(ss,r);
		r.erase(0,1);
		mp[t]=r;
	}
	/*
	map<string,string>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
		cout<<it->first<<endl<<it->second<<endl;
	cout<<endl;
	*/
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		stringstream ss;
		getline(cin,s);
		ss<<s;
		ss>>t;
		if(mp.count(t)==1)
			cout<<mp[t];
		else
			cout<<t;
		while(ss>>t)
		{
			cout<<" ";
			if(mp.count(t)==1)
			cout<<mp[t];
			else
				cout<<t;
		}
		cout<<endl;
	}
	return 0;
}
