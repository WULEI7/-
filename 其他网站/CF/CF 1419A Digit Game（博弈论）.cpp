#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		
		if(n%2==1)
		{
			int flag=0;
			for(int i=0;i<n;i+=2)
				if((s[i]-'0')%2==1)
				{
					flag=1;
					break;
				}
			if(flag==1)
				cout<<"1"<<endl;
			else
				cout<<"2"<<endl;
		}
		else
		{
			int flag=0;
			for(int i=1;i<n;i+=2)
				if((s[i]-'0')%2==0)
				{
					flag=1;
					break;
				}
			if(flag==0)
				cout<<"1"<<endl;
			else
				cout<<"2"<<endl;
		}
	}
	return 0;
}
