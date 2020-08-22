#include <stdio.h>
#include <string.h>
int main()
{
	char n[12];
	scanf("%s",n);//以字符串形式输入数字 
	int len=strlen(n);//获取数字的长度 
	int i,sum=0;//sum记录数位之和 
	for(i=0;i<len;i++)
		sum+=(n[i]-'0');//加上每一位数字 
	printf("%d\n",sum);
	return 0; 
}
