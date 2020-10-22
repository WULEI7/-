#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int len=s.length();
		int num=s[len-1]-'0';
		int ans=10*(num-1)+(1+len)*len/2;
		cout<<ans<<endl;
	}
	return 0;
}
