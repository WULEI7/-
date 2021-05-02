#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,l;
	string s[505];
	cin>>n>>l;
	for(int i=0;i<n;i++)
		cin>>s[i];
	int left=0;
	while(1)
	{
		int flag=1;
		for(int i=1;i<n;i++)
		{
			if(s[i].substr(left)<=s[i-1].substr(left))
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			left--;
			break;
		}
		left++;
	}
	int len=l-left;
	while(1)
	{
		int flag=1;
		for(int i=1;i<n;i++)
		{
			if(s[i].substr(left,len)<=s[i-1].substr(left,len))
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			len++;
			break;
		}
		len--;
	}
	cout<<left+1<<" "<<left+len<<endl;
	return 0;
}
