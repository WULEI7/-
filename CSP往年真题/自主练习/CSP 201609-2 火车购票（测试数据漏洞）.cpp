#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int seat[21][6]={0},left[21],n,p;
	for(int i=1;i<=20;i++)
		left[i]=5;
	cin>>n;
	while(n--)
	{
		cin>>p;
		int flag=1;
		if(p<=5)//����5�ˣ������Ƿ����㹻��������λ 
		{
			for(int i=1;i<=20;i++)
			{
				if(left[i]>=p)
				{
					for(int j=1;j<=5;j++)
						if(seat[i][j]==0)
						{
							p--;
							printf("%d",(i-1)*5+j);//�����ǰ��λ�� 
							if(p>0) printf(" ");
							else printf("\n"); 
							left[i]--;//��ǰһ����λ����1 
							seat[i][j]=1;//��ǰ��λ���۳���� 
							if(p==0) break;//ע������ѡ��λ 
						}
					flag=0;//���ҵ����ڵ���λ 
					break;//�������ѭ���������ظ� 
				}
			}
		}
		if(flag==1)//δ�ҵ����ڵ���λ���򳬹�5�ˣ���ʵ�����в�û�й�Ʊ����5�ŵ������ 
		{
			for(int i=1;i<=20;i++)
			{
				for(int j=1;j<=5;j++)
				{
					if(seat[i][j]==0)
					{
						p--;
						printf("%d",(i-1)*5+j);//�����ǰ��λ�� 
						if(p>0) printf(" ");
						else printf("\n");
						left[i]--;//��ǰһ����λ����1 
						seat[i][j]=1;//��ǰ��λ���۳���� 
						if(p==0) break;//ע������ѡ��λ 
					}
				}
				if(p==0) break;//�������ѭ���������ظ� 
				//�Ͼ䲻дҲ��ͨ�����ԣ����в������ݻ������25*4 
			}
		}
	}
	return 0;
}
