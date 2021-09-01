#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long x,s;
	string xx,ss;
	cin>>x>>s;
	while(x!=0)
	{
		if(x%2==1)
			xx+='1';
		else
			xx+='0';
		x/=2;
	}
	while(s!=0)
	{
		if(s%2==1)
			ss+='1';
		else
			ss+='0';
		s/=2;
	}
	//cout<<xx<<endl<<ss<<endl;
	int len1=xx.length(),len2=ss.length();
	if(len1>len2)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<len1;i++)
	{
		if(xx[i]=='1'&&ss[i]=='0')
		{
			cout<<0<<endl;
			return 0;
		}
	}
	long long ans=1;
	int flag=1;
	for(int i=0;i<len1;i++)
	{
		if(xx[i]=='1'&&ss[i]=='1')
			ans*=2;
		if(xx[i]=='0'&&ss[i]=='1')
			flag=0;
	}
	if(len1<len2)
		flag=0;
	if(flag==1)
		cout<<ans-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
