#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		int len=s.length(),flag=1;
		for(int i=0;i<len;i++)
		{
			if(s[i]!='P'&&s[i]!='A'&&s[i]!='T')
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int posp=0,post=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='P')
				posp=i;
			if(s[i]=='T')
			{
				post=i;
				break;
			}
		}
		for(int i=0;i<posp;i++)
			if(s[i]!='A')
				flag=0;
		for(int i=post+1;i<len;i++)
			if(s[i]!='A')
				flag=0;
		int c1=posp,c2=post-posp-1,c3=len-1-post;
		if(c2==0||c1*c2!=c3)
			flag=0;
		if(flag==1)
		{
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}
