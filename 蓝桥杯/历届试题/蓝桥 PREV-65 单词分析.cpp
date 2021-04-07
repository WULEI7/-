#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int cnt[26];
int main()
{
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
		cnt[s[i]-'a']++;
	int maxn=0,pos=0;
	for(int i=0;i<26;i++)
	{
		if(cnt[i]>maxn)
		{
			maxn=cnt[i];
			pos=i;
		}
	}
	printf("%c\n%d\n",'a'+pos,cnt[pos]);
	return 0;
}
