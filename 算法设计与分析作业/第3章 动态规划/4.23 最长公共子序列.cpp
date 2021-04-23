#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;
char x[100],y[100];
int m,n,c[100][100],b[100][100];//c[i][j]存储xi和yj的最长公共子序列的长度，b[i][j]记录c[i][j]的值是由哪个子问题的解得到的 
void LCSLength(int m,int n,char x[],char y[],int c[][100],int b[][100])//计算最优值 
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
			b[i][j]=1;//向左上方 
		}
		else if(c[i-1][j]>=c[i][j-1])
		{
			c[i][j]=c[i-1][j];
			b[i][j]=2;//向上方 
		}
		else
		{
			c[i][j]=c[i][j-1];
			b[i][j]=3;//向左方 
		}
	}
}
void LCS(int i,int j,char x[],int b[][100])//输出最长公共子序列 
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
	LCSLength(m,n,x,y,c,b);//计算最优值 
	cout<<c[m][n]<<endl;
	if(c[m][n]==0)
		cout<<"None"<<endl;
	else
		LCS(m,n,x,b);//输出最长公共子序列 
	return 0;
}
