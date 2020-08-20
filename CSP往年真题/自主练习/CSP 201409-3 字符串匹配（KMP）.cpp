#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char str[105],pat[105];
int nxt[105];
void getnext()
{
	int i=0,j=-1;
	int len=strlen(pat);//切记要先记录长度，能节省很多时间 
	nxt[0]=-1;
	while(i<len)
	{
		if(j==-1||pat[i]==pat[j])
			nxt[++i]=++j;
		else
			j=nxt[j];
	}
	return;
}
int kmp()
{
	int i=0,j=0,len1=strlen(str),len2=strlen(pat),ans=0;
	while(i<len1)
	{
		if(j==-1||str[i]==pat[j])
			i++,j++;
		else
			j=nxt[j];
		if(j==len2)
			return 1;
	}
	return 0;
}
int main()
{
	int f,n;
	scanf("%s",pat);
	cin>>f>>n;
	int len=strlen(pat);
	if(f==0)
	{
		for(int i=0;i<len;i++)
			if(isupper(pat[i]))
				pat[i]=tolower(pat[i]);
	}//不区分大小写 
	while(n--)
	{
		scanf("%s",str);
		char ss[105];
		strcpy(ss,str);//注意保存原字符串 
		if(f==0)
		{
			len=strlen(str);
			for(int i=0;i<len;i++)
				if(isupper(str[i]))
					str[i]=tolower(str[i]);
		}//不区分大小写 
		getnext();
		if(kmp())
			cout<<ss<<endl;
	}
	return 0;
}
