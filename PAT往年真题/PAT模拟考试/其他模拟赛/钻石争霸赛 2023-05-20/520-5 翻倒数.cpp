#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int a[10]={1,1,0,0,0,0,1,0,1,1};
int b[10]={0,1,0,0,0,0,9,0,8,6};
int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int len=s.length(),flag=1;
		for(int i=0;i<len;i++)
		{
			if(a[s[i]-'0']==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
			for(int i=0;i<len;i++)
				cout<<b[s[i]-'0'];
		else
			cout<<"bu ke neng";
		cout<<endl;
	}
	return 0;
}
