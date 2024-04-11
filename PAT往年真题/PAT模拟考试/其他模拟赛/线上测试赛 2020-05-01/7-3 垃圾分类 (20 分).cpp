#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
int n,t;
string s,ans[5]={"","Gan laji","Shi laji","Ke Hui Shou","You Hai laji"};
map<string,int> mp;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>s>>t;
		mp[s]=t;
	}
	while(1)
	{
		cin>>s;
		if(s=="#") break;
		if(mp.count(s)==0)
			cout<<"?"<<endl;
		else
			cout<<ans[mp[s]]<<endl;
	}
	return 0;
}
