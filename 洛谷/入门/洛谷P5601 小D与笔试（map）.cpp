#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string,string> mp;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	string r,s,t;
	cin>>n>>m;
	while(n--)
	{
		cin>>s>>t;
		mp[s]=t;
	}
	while(m--)
	{
		cin>>r;
		s=mp[r];
		for(int i=1;i<=4;i++)
		{
			cin>>t;
			if(t==s&&i==1)
				printf("A\n");
			if(t==s&&i==2)
				printf("B\n");
			if(t==s&&i==3)
				printf("C\n");
			if(t==s&&i==4)
				printf("D\n");
		}
	}
	return 0;
}
