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
	int len=strlen(pat);//�м�Ҫ�ȼ�¼���ȣ��ܽ�ʡ�ܶ�ʱ�� 
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
	}//�����ִ�Сд 
	while(n--)
	{
		scanf("%s",str);
		char ss[105];
		strcpy(ss,str);//ע�Ᵽ��ԭ�ַ��� 
		if(f==0)
		{
			len=strlen(str);
			for(int i=0;i<len;i++)
				if(isupper(str[i]))
					str[i]=tolower(str[i]);
		}//�����ִ�Сд 
		getnext();
		if(kmp())
			cout<<ss<<endl;
	}
	return 0;
}
