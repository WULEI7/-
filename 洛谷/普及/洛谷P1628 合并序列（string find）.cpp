#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm> 
using namespace std;
string s[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string str;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n);
	cin>>str;
	for(int i=0;i<n;i++)
	{
		if(s[i].find(str)==0)
			cout<<s[i]<<endl;
	}
	return 0;
}
