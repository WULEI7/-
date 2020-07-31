#include <stdio.h>
int main()
{
	int n,sum=0;//sum记录数位之和 
	scanf("%d",&n);
	while(n>0)
	{
		sum+=(n%10);//sum加上当前数字的个位 
		n/=10;//当前数字整除以10 
	}
	printf("%d\n",sum);
	return 0;
}
