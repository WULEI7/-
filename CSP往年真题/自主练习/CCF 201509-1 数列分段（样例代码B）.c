#include <stdio.h>
int main()
{
	int n,num[1005],cnt=1,i;//cnt用来记录分段的数量，初始为1 
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		if(i>1&&num[i]!=num[i-1])
			cnt++;//从第二个数开始，判断如果当前输入的数字和前一个数字不同，那么分段的数量加1 
	}
	printf("%d\n",cnt);
	return 0;
}
