#include <stdio.h>
#include <math.h> 
int main()
{
	int i=1;//��i�������Ϊ����ż����Ϊ�� 
	double PI=0.0;//�ۼ�PI��ֵ 
	double temp;//��ǰ���ֵ�����������ţ� 
	while(1)
	{
		temp=1.0/(i*2-1);//ע��ȷ�����ͺͶ����һ�£����i�õ���int���ͣ�ע�����д��1.0�����߼���һ��(double)ǿ������ת�� 
		if(temp<pow(10,-6))//ע��C����^��λ������ţ�ָ��Ҫ��pow���� 
			break;
		/*
		if(i%2==1) 
			PI+=temp;
		else
			PI+=-temp;
		*/
		PI+=pow(-1,i+1)*temp;//�������п��Ժϲ�д����� 
		i++;
	}
	PI*=4.0;
    printf("PI=%10.8f\n",PI);
    return 0;
}
