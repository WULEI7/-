#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	int n;
	while(cin>>s>>n)
	{
		while(n>0)
		{
			string::iterator it;
			for(it=s.begin();it!=s.end();it++)
				if(*(it+1)<*it||it+2==s.end())
				{
					if(*it>=*(it+1))
						s.erase(it);
					else
						s.erase(it+1);
					n--;
					break; 
				}
		}
		int len=s.length(),pos=9999;
		for(int i=0;i<len;i++)
			if(s[i]!='0')
			{
				pos=i;
				break;
			}
		if(pos==9999)
		{
			printf("0\n");
			continue;
		}
		for(int i=pos;i<len;i++)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
