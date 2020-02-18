#include <stdio.h>
int main()
{
	int cm,kg;
	char xb;
	float bz;
	printf("请输入你的性别(m/f)，身高cm，体重kg：\n");
	scanf("%c,%d,%d",&xb,&cm,&kg);
	if(xb=='m') bz=(float)(cm-100)*0.9;
	else if(xb=='f'||xb=='F') bz=(float)(cm-100)*0.9-2.5;
	printf("您的标准体重是%.2fkg\n",bz);
	if(kg<bz*0.9) printf("您偏瘦。\n");
	else if(kg>=bz*0.9&&kg<=bz*1.1) printf("您是标准体重。\n");
	else if(kg>bz*1.1&&kg<bz*1.2) printf("您超重了。\n");
	else if(kg>bz*1.2&&kg<bz*1.3) printf("您属于轻度肥胖。\n");
	else if(kg>bz*1.3&&kg<bz*1.5) printf("您属于中度肥胖。\n");
	else if(kg>bz*1.5) printf("您属于重度肥胖。\n");
	return 0;
}
