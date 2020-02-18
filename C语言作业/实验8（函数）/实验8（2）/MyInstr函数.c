#include <stdio.h>
#include <string.h>
int MyInstr(char a[],char b)
{
	int i,k,x=0;
	k=strlen(a);
	for(i=0;i<k;i++)
		if(a[i]==b)
		{
			x=i+1;
			break;
		}
	return x;
}
int main()
{
	int n;
	char a[100];
	printf("请输入待检测的字符串信息：\n");
	gets(a);
	n=MyInstr(a,'*');
	if(n==0) printf("该字符串不含有非法字符*\n");
	else printf("该字符串的第%d位置有非法字符*\n",n);
	return 0;
}
