#include <cstdio>
#include <iostream>
using namespace std;
double a,b,c,d;
double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
	int tot=0;
	cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++)
	{
		if(f(i)==0)//�ж���˵��Ƿ�Ϊ���̵Ľ� 
		{
			tot++;
			printf("%.2f",double(i));//������int���͵� 
			if(tot<3)
				printf(" ");
		}
		else if(f(i)*f(i+1)<0)//�����ڵĿ����� 
		{
			tot++;
			double l=i,r=i+1,mid;
			while(r-l>0.001)
			{
				mid=l+(r-l)/2;
				if(f(mid)*f(l)>0)
					l=mid;
				else
					r=mid;
			}
			printf("%.2f",mid);
			if(tot<3)
				printf(" ");
		}
		if(tot==3) break;//�����������ͽ��� 
	}
	return 0;
}
