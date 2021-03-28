#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int len,str[1000005];
int nxt[1000005];
void getnext(int *str)
{
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<len)
	{
		if(j==-1||str[i]==str[j])
			nxt[++i]=++j;
		else
			j=nxt[j];
	}
	return;
}//KMPËã·¨ 
int main()
{
	scanf("%d",&len);
	for(int i=len-1;i>=0;i--)
		scanf("%d",&str[i]);
	getnext(str);
	int k,p,sum=1999999999;
	for(int i=len;i>=1;i--)
	{
		int tk=len-i;
		int tp=i-nxt[i];
		if(tk+tp<sum||tk+tp==sum&&tp<p)
		{
			sum=tk+tp;
			k=tk;p=tp;
		}
	}
	printf("%d %d\n",k,p);
	return 0;
}
