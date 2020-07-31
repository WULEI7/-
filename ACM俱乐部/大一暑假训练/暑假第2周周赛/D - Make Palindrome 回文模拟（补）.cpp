#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int cnt[26]={0};
	string s,p="";
	cin>>s;
	int len=s.length();
	/*int huiwen=1;
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-1-i])
		{
			huiwen=0;
			break;
		}
	}
	if(huiwen==1)
	{
		cout<<s<<endl;
		return 0;
	}*///原本是回文串也要按照字典序，因为变动字母顺序不算次数 
	for(int i=0;i<len;i++)
		cnt[s[i]-'a']++;//提取字符串中每个字母的个数 
	if(len%2==0)//字符串长度为偶数 
	{
		for(int i=0;i<26;i++)
		{
			if(cnt[i]%2)
			{
				cnt[i]++;
				for(int j=25;j>=0;j--)
				{
					if(cnt[j]%2)
					{
						cnt[j]--;
						break;
					}
				}
			}
		}
		for(int i=0;i<26;i++)
			if(cnt[i])
			{
				for(int j=0;j<cnt[i]/2;j++)
					p+=('a'+i);
			}
		int l=p.length();
		for(int i=0;i<l;i++)
			printf("%c",p[i]);
		for(int i=l-1;i>=0;i--)
			printf("%c",p[i]);
		printf("\n");
	}
	if(len%2==1)//字符串长度为奇数 
	{
		int jishu=0;
		for(int i=0;i<26;i++)
			if(cnt[i]%2)
				jishu++;
		if(jishu>1)
		{
			for(int i=0;i<26;i++)
			{
				if(cnt[i]%2)
				{
					cnt[i]++;
					int flag=1;
					for(int j=25;j>=0;j--)
					{
						if(cnt[j]%2&&j>i)
						{
							flag=0;
							cnt[j]--;
							break;
						}
					}
					if(flag)
						for(int j=25;j>=0;j--)
						{
							if(cnt[j]&&j>i)
							{
								cnt[j]--;
								break;
							}
						}
					jishu-=2;
				}
				if(jishu==1) break;
			}
		}
		char dan;
		for(int i=0;i<26;i++)
		{
			if(cnt[i]&&cnt[i]%2==0)
			{
				for(int j=0;j<cnt[i]/2;j++)
					p+=('a'+i);
			}
			if(cnt[i]%2)
			{
				for(int j=0;j<cnt[i]/2;j++)
					p+=('a'+i);
				dan=('a'+i);
			}
		}
		int l=p.length();
		for(int i=0;i<l;i++)
			printf("%c",p[i]);
		printf("%c",dan);
		for(int i=l-1;i>=0;i--)
			printf("%c",p[i]);
		printf("\n");
	}
	return 0;
}
