#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[100005];
int nxt[100005];
void getnext(char *str)
{
	int i=0,j=-1;
	int len=strlen(str);
	nxt[0]=-1;
	while(i<len)
	{
		if(j==-1||str[i]==str[j])
			nxt[++i]=++j;
		else
			j=nxt[j];
	}
	return;
}//KMP算法 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		int len=strlen(str);
		bool same=1;
		for(int i=0;i<len-1;i++)
		{
			if(str[i]!=str[i+1])
			{
				same=0;
				break;
			}
		}
		if(same)
		{
			printf("0\n");
			continue;
		}//如果全是相同字符 
		getnext(str);
		if(nxt[len]==0)//如果最大相同前后缀为0 
			printf("%d\n",len);
		else
		{
			int zhouqi=len-nxt[len];
			int temp=zhouqi-len%zhouqi;
			if(temp==zhouqi)
				printf("0\n");
			else
				printf("%d\n",zhouqi-len%zhouqi);
		}
	}
	return 0;
}
