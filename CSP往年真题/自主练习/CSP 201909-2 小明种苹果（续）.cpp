#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,m,t=0,d=0,e=0,diao[1005]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		int a,temp=0;//��ǰ����ƻ������ 
		cin>>temp;//��һ�������ʼƻ������ 
		for(int j=2;j<=m;j++)
		{
			cin>>a;
			if(a>0)//����ͳ�� 
			{
				if(a<temp)//�е��� 
				{
					diao[i]=1;
					temp=a;
				}	
			}
			else//��� 
				temp+=a;
		}
		t+=temp;//����ƻ������ 
	}
	for(int i=1;i<=n;i++)//ͳ�Ƶ������ 
	{
		if(diao[i])
			d++;
		if(diao[(i-1)%n+1]&&diao[i%n+1]&&diao[(i+1)%n+1])
			e++;
	}
	cout<<t<<" "<<d<<" "<<e<<endl;
	return 0; 
}
