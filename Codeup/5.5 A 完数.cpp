#include <iostream>
#include <cstdio>
#include <cmath> 
using namespace std;
bool isWanshu[10005]; 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=6;i<=10000;i++)//1�������� 
	{
		int s=sqrt(i);
		int t=1;
		for(int j=2;j<=s;j++)//i������i�����ӣ�����ֱ�Ӱ�1�ӽ�ȥ����2��ʼ�ж� 
		{
			if(i%j==0)
			{
				t+=j;
				t+=i/j;
				if(j*j==i) t-=j;//����Ǹ���i��ֻ����һ�� 
			}
		}
		if(t==i) isWanshu[i]=true;//������ 
	}
	//�����׳ƴ�������ظ����� 
	//���1-10000֮������� 
	//for(int i=1;i<=10000;i++)
	//	if(isWanshu[i])
	//		cout<<i<<" "; 
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			if(isWanshu[i])
				cout<<i<<" ";//����������ύ��AC�� 
		//�����PATƽ̨�������ϸ�ĩβ���ܶ�����ո�Ҫ��vector��� 
		cout<<endl;
	}
	return 0;
}
