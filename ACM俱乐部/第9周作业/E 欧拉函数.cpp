#include <iostream>
using namespace std;
int Euler(int n)
{
	int ans=1,temp=1;//��ans��¼ŷ��������ֵ����temp��¼��һ�γ����� 
	while(n>1)
	{
		for(int i=2;i<=n;i++)
			if(n%i==0)//����һ�μ�������һ��ѭ�������Բ���Ҫ�ж�i�Ƿ�Ϊ���� 
			{
				n/=i;
				if(i==temp)
					ans*=i;//������Ѿ�������������ans����i 
				else
				{
					ans*=i-1;
					temp=i;
				}//�����û�г�����������ans����i-1 
				break;
			}
	}
	return ans;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		cout<<Euler(n)<<endl;
	}
	return 0;
}
