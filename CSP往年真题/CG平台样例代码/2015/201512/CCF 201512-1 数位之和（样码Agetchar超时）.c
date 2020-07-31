#include <stdio.h>
int main()
{
	char c;
	int sum=0;
	while((c=getchar())!='\n')//以字符形式输入每一位 
	{
		sum+=c-'0';//答案加上每一位的数值 
	} 
	printf("%d\n",sum);
	return 0;
}
