#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
map<pair<int,int>,int> mp;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,minn=200001;
		string s;
		cin>>n>>s;
		int x=0,y=0,l=-1,r=-1;
		mp.clear();
		mp[{0,0}]=1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='L')
				x--;
			if(s[i]=='R')
				x++;
			if(s[i]=='U')
				y++;
			if(s[i]=='D')
				y--;
			if(mp.count({x,y}))
			{
				if(i+1-mp[{x,y}]<minn)
				{
					l=mp[{x,y}];
					r=i+1;
					minn=r-l;
				}
			}
			mp[{x,y}]=i+2;
		}
		if(l!=-1&&r!=-1)
			cout<<l<<" "<<r<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
