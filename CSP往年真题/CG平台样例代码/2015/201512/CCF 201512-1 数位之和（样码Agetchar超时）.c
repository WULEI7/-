#include <stdio.h>
int main()
{
	char c;
	int sum=0;
	while((c=getchar())!='\n')//���ַ���ʽ����ÿһλ 
	{
		sum+=c-'0';//�𰸼���ÿһλ����ֵ 
	} 
	printf("%d\n",sum);
	return 0;
}
