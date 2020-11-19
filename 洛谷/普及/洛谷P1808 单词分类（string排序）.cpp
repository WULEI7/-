#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s;
	map<string,int> mp;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		mp[s]++;
	}
	int ans=mp.size();
	cout<<ans<<endl;
	return 0;
}
