#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		map<string,int> mp;
		string str;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			mp[str]++;	
		}
		map<string,int>::iterator it;
		int maxn=0;
		string ans;
		for(it=mp.begin();it!=mp.end();it++)
		{
			if(it->second>maxn)
			{
				maxn=it->second;
				ans=it->first;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
