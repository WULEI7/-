#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	char c[11]="Simon says";
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		string s;
		getline(cin,s);
		int flag=1;
		for(int i=0;i<10;i++)
			if(s[i]!=c[i])
			{
				flag=0;
				break;
			}
		if(flag)
		{ 
			for(int i=10;i<s.length();i++)
				printf("%c",s[i]);
			printf("\n");
		}
	}
	return 0;
}
