#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s,t[1005];
	map<string,int> mp1;
	map<string,int> mp2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mp1[s]=i;
		t[i]=s;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mp2[s]=i;
	}
	int temp=0;
	string ans;
	for(int i=1;i<=n;i++)
	{
		int rise=mp1[t[i]]-mp2[t[i]];
		if(rise>temp)
		{
			temp=rise;
			ans=t[i];
		}
	}
	if(temp==0)
		cout<<"suspicious"<<endl;
	else
		cout<<ans<<endl;
	return 0; 
}
