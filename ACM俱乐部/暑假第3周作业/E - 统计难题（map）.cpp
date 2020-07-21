#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	map<string,int> qianzhui;
	string s;
	while(getline(cin,s))
	{
		if(s=="") break;
		int len=s.length();
		string ss="";
		for(int i=0;i<len;i++)
		{
			ss+=s[i];
			qianzhui[ss]++;
		}
	}
	while(cin>>s)
		cout<<qianzhui[s]<<endl;
	return 0;
}
