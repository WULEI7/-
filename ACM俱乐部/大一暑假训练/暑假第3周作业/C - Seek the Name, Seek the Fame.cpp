#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[400005];
int nxt[400005],ans[400005];
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
		int len=strlen(str);
		getnext(str);
		int k=0,t=len;
		while(t>0)
		{
			t=nxt[t];
			ans[k++]=t;
		}//�Ӵ���С����ͬǰ��׺�����������ȱ��� 
		for(int i=k-2;i>=0;i--)
			printf("%d ",ans[i]);
		printf("%d\n",len);//���ȱ���Ҳ���� 
	}
	return 0;
}
