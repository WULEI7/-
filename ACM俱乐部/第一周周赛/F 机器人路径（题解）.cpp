#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<pair<int,int>,int> mp;
int main()
{
	int t,n;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		int x=0,y=0,l=0,r=n;
		mp.clear();
		mp[{0,0}]=1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='L')
				x--;
			else if(s[i]=='R')
				x++;
			else if(s[i]=='U')
				y++;
			else
				y--;
			if(mp[{x,y}]!=0&&r-l>i-mp[{x,y}]+1)
			{
				l=mp[{x,y}];
				r=i+1;
			}
			mp[{x,y}]=i+2;
		}
		if(l==0)
			cout<<-1<<endl;
		else
			cout<<l<<" "<<r<<endl;
	}
	return 0;
}

