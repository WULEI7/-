#include <stdio.h>
#include <string.h>
int main()
{
	char n[12];
	scanf("%s",n);//���ַ�����ʽ�������� 
	int len=strlen(n);//��ȡ���ֵĳ��� 
	int i,sum=0;//sum��¼��λ֮�� 
	for(i=0;i<len;i++)
		sum+=(n[i]-'0');//����ÿһλ���� 
	printf("%d\n",sum);
	return 0; 
}
