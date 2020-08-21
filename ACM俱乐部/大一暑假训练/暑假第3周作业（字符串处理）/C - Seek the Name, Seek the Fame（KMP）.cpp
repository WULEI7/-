#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[400005];
int nxt[400005],ans[400005];
void getnext(char *str)
{
	int i=0,j=-1;
	int len=strlen(str);//切记要先记录长度，否则会超时 
	nxt[0]=-1;
	while(i<len)
	{
		if(j==-1||str[i]==str[j])
			nxt[++i]=++j;
		else
			j=nxt[j];
	}
	return;
}
int main()
{
	while(~scanf("%s",str))
	{
		int len=strlen(str);
		getnext(str);
		int k=0,t=len;
		while(t>0)
		{
			t=nxt[t];
			ans[k++]=t;
		}//从大往小找相同前后缀（不包含长度本身） 
		for(int i=k-2;i>=0;i--)
			printf("%d ",ans[i]);
		printf("%d\n",len);//长度本身也符合 
	}
	return 0;
}
