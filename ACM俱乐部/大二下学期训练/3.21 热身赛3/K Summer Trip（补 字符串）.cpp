#include <iostream>
#include <cstdio>
#include <string> 
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int len=s.length();
	int ans=0;
	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(s[j]==s[i]) break;
			int flag=1;
			if(s[j]==s[j-1]) continue;//此处必须加上，否则会超时 
			for(int k=i+1;k<j;k++)
			{
				if(s[k]==s[j])
				{
					flag=0;
					break;
				}
			}
			if(flag==1) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
