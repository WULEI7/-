#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000005];
int nxt[1000005];
void getnext(char *str)
{
	int i=0,j=-1;
	int len=strlen(str);//�м�Ҫ�ȼ�¼���ȣ�����ᳬʱ 
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
		if(str[0]=='.') break;
		int len=strlen(str);
		getnext(str);
		int k=len-nxt[len]; 
		if(len%k==0)//�Ƿ������С����k 
			printf("%d\n",len/k);
		else
			printf("1\n");
	}
	return 0;
}
