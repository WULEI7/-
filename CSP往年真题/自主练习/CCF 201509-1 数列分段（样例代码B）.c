#include <stdio.h>
int main()
{
	int n,num[1005],cnt=1,i;//cnt������¼�ֶε���������ʼΪ1 
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		if(i>1&&num[i]!=num[i-1])
			cnt++;//�ӵڶ�������ʼ���ж������ǰ��������ֺ�ǰһ�����ֲ�ͬ����ô�ֶε�������1 
	}
	printf("%d\n",cnt);
	return 0;
}
