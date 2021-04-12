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
		int flag=1;
		int len=s.length();
		for(int i=0;i<len;i++)
			if(s[i]!='a')
			{
				flag=0;
				break;
			}
		if(flag==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int left=0,right=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='a')
				left++;
			else
				break;
		}
		for(int i=len-1;i>=0;i--)
		{
			if(s[i]=='a')
				right++;
			else
				break;
		}
		if(left<right)
			s=s+'a';
		else
			s='a'+s;
		cout<<"YES"<<endl;
		cout<<s<<endl;
	}
	return 0;
}
