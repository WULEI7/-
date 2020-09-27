#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int len=s.length(),flag=1,ans=0;
	for(int i=0;i<len-1;i++)
	{
		if(s[i]==s[i+1]) continue;
		ans++;
		flag=!(s[i]-'0');
	}
	if(!flag) ans++;
	cout<<ans<<endl;
	return 0;
}
