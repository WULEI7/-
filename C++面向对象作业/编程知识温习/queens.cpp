#include <bits/stdc++.h>
using namespace std;
int board[9][9]={0};//����ÿ���ʼֵ��Ϊ0 
int main()
{
	char a[9];
	int n,i,j,row,flag=1;
	for(n=1;n<=8;n++)
	{
		cin>>a[n];//����
		if(a[n]=='*')
			row=n;//����*�����¼���е�λ�� 
 	else
		{
			for(i=1;i<=8;i++)
				board[i][a[n]-'0']=1;
			for(j=1;j<=8;j++)
				board[n][j]=1;
			for(i=n,j=a[n]-'0';i>=1&&i<=8&&j>=1&&j<=8;i--,j--)
				board[i][j]=1;
			for(i=n,j=a[n]-'0';i>=1&&i<=8&&j>=1&&j<=8;i++,j++)
				board[i][j]=1;
			for(i=n,j=a[n]-'0';i>=1&&i<=8&&j>=1&&j<=8;i--,j++)
				board[i][j]=1;
			for(i=n,j=a[n]-'0';i>=1&&i<=8&&j>=1&&j<=8;i++,j--)
				board[i][j]=1;
		}//�������ϻʺ��ܹ�����������λ�ø�ֵΪ1 
	} 
	for(n=1;n<=8;n++)
		if(board[row][n]==0)
		{
			cout<<n;
			flag=0;
		}//�Կ���ÿ����м�鲢����𰸣���ֻ������Ψһ�Ļ����޽� 
	if(flag)
		cout<<"No Answer";
	return 0;
}//����⻹��һ��˼·���߸��ʺ��Ѿ��ź��ˣ��ų����������ֻʣ��Ψһһ�������Ǵ𰸵ĸ��ӣ�ֻ����ø��ӵ�б�����Ƿ��Ѿ��ڷ��˻ʺ󼴿ɡ� 
