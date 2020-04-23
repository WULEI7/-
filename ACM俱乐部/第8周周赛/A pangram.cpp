#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	int n,cnt[26];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		memset(cnt,0,sizeof(cnt));
		string s;
		getline(cin,s);
		for(int i=0;i<s.length();i++)
		{
			if(s[i]>='a'&&s[i]<='z')
				cnt[s[i]-'a']++;
			else if(s[i]>='A'&&s[i]<='Z')
				cnt[s[i]-'A']++;
		}
		int flag=1;
		for(int i=0;i<26;i++)
			if(cnt[i]==0)
			{
				flag=0;
				break;
			}
		if(flag)
			printf("pangram\n");
		else
		{
			printf("missing ");
			for(int i=0;i<26;i++)
				if(cnt[i]==0)
					printf("%c",'a'+i);
			printf("\n");
		}
	}
	return 0;
}
