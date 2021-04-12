#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s[10005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	int len=s[0].length();
	for(int j=0;j<len;j++)
		if(s[0][j]=='9')
			s[0][j]='6';//将第一个数的所有9换成6 
	int flag=1;
	for(int i=1;i<n;i++)
	{
		len=s[i].length();
		if(len<s[i-1].length())
		{
			flag=0;
			break;
		}//如果长度比前一个数小，则不可能 
		if(len>s[i-1].length())
		{
			for(int j=0;j<len;j++)
				if(s[i][j]=='9')
					s[i][j]='6';
			continue; 
		}//如果长度比前一个数大，则将所有9换成6即可 
		for(int j=0;j<len;j++)
			if(s[i][j]=='6')
				s[i][j]='9';
		if(s[i-1].compare(s[i])>0)
		{
			flag=0;
			break;
		}//如果将所有6换成9还比前一个数小，则不可能 
		for(int j=0;j<len;j++)
		{
			if(s[i][j]=='9')
			{
				s[i][j]='6';
				if(s[i-1].compare(s[i])>0)
					s[i][j]='9';
			}
		}//从前往后试把9换成6 
		for(int j=len-1;j>=0;j--)
		{
			if(s[i][j]=='9')
			{
				s[i][j]='6';
				if(s[i-1].compare(s[i])>0)
					s[i][j]='9';
			}
		}//从后往前试把9换成6 
	}
	if(flag==0)
		cout<<"impossible"<<endl;
	if(flag==1)
	{
		cout<<"possible"<<endl;
		for(int i=0;i<n;i++)
			cout<<s[i]<<endl;
	}
	return 0;
}
