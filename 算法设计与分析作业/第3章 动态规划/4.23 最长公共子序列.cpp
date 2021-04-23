#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;
char x[100],y[100];
int m,n,c[100][100],b[100][100];//c[i][j]�洢xi��yj������������еĳ��ȣ�b[i][j]��¼c[i][j]��ֵ�����ĸ�������Ľ�õ��� 
void LCSLength(int m,int n,char x[],char y[],int c[][100],int b[][100])//��������ֵ 
{
	for(int i=0;i<=m;i++)
		c[i][0]=0;
	for(int j=0;j<=n;j++)
		c[0][j]=0;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(x[i]==y[j])
		{
			c[i][j]=c[i-1][j-1]+1;
			b[i][j]=1;//�����Ϸ� 
		}
		else if(c[i-1][j]>=c[i][j-1])
		{
			c[i][j]=c[i-1][j];
			b[i][j]=2;//���Ϸ� 
		}
		else
		{
			c[i][j]=c[i][j-1];
			b[i][j]=3;//���� 
		}
	}
}
void LCS(int i,int j,char x[],int b[][100])//�������������� 
{
	if(i==0||j==0)
		return;
	if(b[i][j]==1)
	{
		LCS(i-1,j-1,x,b);
		cout<<x[i];
	}
	else if(b[i][j]==2)
		LCS(i-1,j,x,b);
	else
		LCS(i,j-1,x,b);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	stringstream scin;
	string s;
	getline(cin,s);
	scin<<s;
	int pos=0;
	char t;
	while(scin>>t)
		x[++pos]=t;
	m=pos;
	scin.clear();
	getline(cin,s);
	scin<<s;
	pos=0;
	while(scin>>t)
		y[++pos]=t;
	n=pos;
	LCSLength(m,n,x,y,c,b);//��������ֵ 
	cout<<c[m][n]<<endl;
	if(c[m][n]==0)
		cout<<"None"<<endl;
	else
		LCS(m,n,x,b);//�������������� 
	return 0;
}
