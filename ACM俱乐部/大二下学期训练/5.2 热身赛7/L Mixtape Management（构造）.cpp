#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		cout<<1;//������ǰ���� 
		if(t<10)
			cout<<0;
		cout<<i;//�����ֵ��� 
		while(t--)
			cout<<0;//���ƴ�С˳�� 
		cout<<" ";
	}
	return 0;
}
