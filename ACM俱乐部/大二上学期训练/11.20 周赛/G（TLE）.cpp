#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		map<char,int> mp;
		string s,t,z;
		cin>>s>>t;
		int len1=s.length();
		for(int i=0;i<26;i++)
			mp['a'+i]=0;
		for(int i=0;i<len1;i++)
			mp[s[i]]++;
		int len2=t.length();
		int flag=0;
		for(int i=0;i<len2;i++)
			if(mp[t[i]]==0)
			{
				flag=1;
				break;
			}
		if(flag==1)
		{
			cout<<"-1"<<endl;
			continue;
		}
		int len3=0,ans=0;
		while(len3<len2)
		{
			for(int i=0;i<len1&&len3<len2;i++)
			{
				if(s[i]==t[len3])
					len3++;
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
