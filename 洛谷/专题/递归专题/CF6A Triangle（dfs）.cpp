#include <bits/stdc++.h>
using namespace std;
int n,a[10],b[3],flag=0;
void dfs(int cur,int pla)//cur��ʾĿǰb�����������ֵĸ�����pla��ʾǰһ���������a�����е�λ�� 
{
	if(cur==3)
	{
		if(b[0]+b[1]>b[2])
			flag=2;
		if(b[0]+b[1]==b[2]&&!flag)
			flag=1;
	}//��b����������3������ʱ�ж�״̬ 
	else
	{
		for(int i=pla;i<n;i++)
		{
			b[cur]=a[i];
			dfs(cur+1,i+1);
		}
	}//û����ʱ������b����������������������ֱ�����������a������λ�ÿ��� 
	return;
}//��ϰдdfs�������Խ���������ձ��Ե����⣨ľ����4������ʱ�� 

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];//a���������ľ������ 
	sort(a,a+n);//��a�����С���������Ա�������� 
	dfs(0,0);
	if(flag==0) cout<<"IMPOSSIBLE";
	if(flag==1) cout<<"SEGMENT";
	if(flag==2) cout<<"TRIANGLE";//����flag״̬������ 
	return 0;
}
