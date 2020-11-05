#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000005],pat[1000005];
int nxt[1000005];
void getnext()
{
	int i=0,j=-1;
	int len=strlen(pat);
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
void kmp()
{
	int i=0,j=0,len1=strlen(str),len2=strlen(pat);
	while(i<len1)
	{
		if(j==-1||str[i]==pat[j])
			i++,j++;
		else
			j=nxt[j];
		if(j==len2)
			printf("%d\n",i-len2+1);
	}
}
int main()
{
	scanf("%s",&str[0]);
	scanf("%s",&pat[0]);
	getnext();
	kmp();
	int len=strlen(pat);
	for(int i=1;i<=len;i++)
		printf("%d ",nxt[i]);
	printf("\n");
	return 0;
}
