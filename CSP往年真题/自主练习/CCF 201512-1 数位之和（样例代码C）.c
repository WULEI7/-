#include <stdio.h>
int main()
{
	int n,sum=0;//sum��¼��λ֮�� 
	scanf("%d",&n);
	while(n>0)
	{
		sum+=(n%10);//sum���ϵ�ǰ���ֵĸ�λ 
		n/=10;//��ǰ����������10 
	}
	printf("%d\n",sum);
	return 0;
}
