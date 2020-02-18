#include <stdio.h>
int alpha(char n)
{
	int x;
	if((n>=65&&n<=90)||(n>=97&&n<=122)) x=1;
	else x=0;
	return x;
}
int main()
{
	char a[100];
	int sum=0,i;
	printf("请输入待检测的字符串信息：\n");
	gets(a);
	for(i=0;a[i]!='\0';i++)
		sum+=alpha(a[i]);
	printf("待检测的字符串中含有%d个字母字符",sum);
	return 0;
}
