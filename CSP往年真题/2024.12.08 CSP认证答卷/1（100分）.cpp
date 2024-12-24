#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int n,k,x,y;
	string s;
	cin>>n>>k;
	while(k--)
	{
		cin>>x>>y>>s;
		int len=s.length();
		for(int i=0;i<len;i++)
		{
			if(s[i]=='f')
			{
				if(y+1<=n)
					y++;
			}
			else if(s[i]=='b')
			{
				if(y-1>=1)
					y--;
			}
			else if(s[i]=='r')
			{
				if(x+1<=n)
					x++;
			}
			else if(s[i]=='l')
			{
				if(x-1>=1)
					x--;
			}
		}
		cout<<x<<" "<<y<<endl;
	}	
	return 0;
}