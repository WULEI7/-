#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	while(cin>>s)
	{
		if(s[0]=='.') break;
		int len=s.length();
		for(int i=1;i<=len;i++)
		{
			if(len%i==0)
			{
				bool flag=1;
				for(int j=i;j<len;j++)
					if(s[j]!=s[j%i])
					{
						flag=0;
						break;
					}
				if(flag)
				{
					printf("%d\n",len/i);
					break;
				}
			}
		}
	}
	return 0;
}
