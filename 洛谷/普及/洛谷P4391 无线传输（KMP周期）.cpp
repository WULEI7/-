#include <cstdio>
#include <cstring>
char str[1000005];
int nxt[1000005];
void getnext()
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
}//KMPËã·¨ 
int main()
{
	int len;
	scanf("%d",&len);
	scanf("%s",&str[0]);
	getnext();
	int zhouqi=len-nxt[len];
	printf("%d\n",zhouqi);
	return 0;
}
