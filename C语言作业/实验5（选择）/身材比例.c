#include <stdio.h>
int main()
{
	int cm,kg;
	char xb;
	float bz;
	printf("����������Ա�(m/f)�����cm������kg��\n");
	scanf("%c,%d,%d",&xb,&cm,&kg);
	if(xb=='m') bz=(float)(cm-100)*0.9;
	else if(xb=='f') bz=(float)(cm-100)*0.9-2.5;
	printf("���ı�׼������%.2fkg\n",bz);
	if(kg<bz*0.9) printf("��ƫ�ݡ�\n");
	else if(kg>=bz*0.9&&kg<=bz*1.1) printf("���Ǳ�׼���ء�\n");
	else if(kg>bz*1.1&&kg<bz*1.2) printf("�������ˡ�\n");
	else if(kg>bz*1.2&&kg<bz*1.3) printf("��������ȷ��֡�\n");
	else if(kg>bz*1.3&&kg<bz*1.5) printf("�������жȷ��֡�\n");
	else if(kg>bz*1.5) printf("�������ضȷ��֡�\n");
	return 0;
}
