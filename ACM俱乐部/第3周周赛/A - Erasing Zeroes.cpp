#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int flag1=0,flag2=0,k1,k2;
		for(int i=0;i<s.length();i++)
			if(s[i]=='1')
			{flag1=1;k1=i;break;}
		for(int i=s.length()-1;i>=0;i--)
			if(s[i]=='1')
			{flag2=1;k2=i;break;}
		if(flag1==0&&flag2==0)
			cout<<"0"<<endl;
		else
		{
			int ans=0;
			for(int i=k1;i<=k2;i++)
				if(s[i]=='0')
					ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}
