#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000005],pat[10005];
int nxt[10005];
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
			ans++;
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&pat[0]);
		scanf("%s",&str[0]);
		getnext();
		printf("%d\n",kmp());
	}
	return 0;
}
