#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c,x;//c���뷽�̣�x��δ֪������ĸ 
	int flag=1,lr=1,k=0,b=0,num=0,isnum=0;//flag���������lr��ʾ�Ⱥ����ң�������ת��Ϊ kx+b=0 ����ʽ��kΪδ֪��ϵ����bΪ������num���ȡ�����֣�isnum����Ƿ�������� 
	float ans=0;
	while(c!='\n')
	{
		c=getchar();//ÿ�ζ�ȡһ���ַ��������������ж� 
		if(c=='-')
		{
			b+=lr*flag*num;
			num=0;
			flag=-1;
			isnum=0;
		}
		if(c=='+')
		{
			b+=lr*flag*num;
			num=0;
			flag=1;
			isnum=0;
		}
		if(c=='=')
		{
			b+=lr*flag*num;
			num=0;
			flag=1;
			lr=-1;
			isnum=0;
		}
		if(c>='0'&&c<='9')
		{
			num=num*10+c-'0';
			isnum=1;
		}
		if(c>='a'&&c<='z')
		{
			x=c;
			if(isnum)
			{
				k+=lr*flag*num;
				num=0;
			}
			else k+=lr*flag;
			isnum=0;
		}
	}
	b+=lr*flag*num;//���������һ���ǳ��������b 
	ans=float(-b*1.0/k);
	if(ans==0) ans=0;//���� kx=0 kΪ��������� 
	printf("%c=%.3f",x,ans);
	return 0;
}
