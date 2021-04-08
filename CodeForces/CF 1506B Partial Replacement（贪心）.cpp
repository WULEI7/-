#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,d,first,last;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>d>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='*')
			{
				first=i;
				break;
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='*')
			{
				last=i;
				break;
			}
		}
		if(first==last)
			cout<<"1"<<endl;
		else
		{
			int ans=1,pos=first;
			while(pos<last)
			{
				for(int j=pos+d;j>=pos+1-d;j--)
				{
					if(j>last) continue;
					if(s[j]=='*')
					{
						ans++;
						pos=j;
						break;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
