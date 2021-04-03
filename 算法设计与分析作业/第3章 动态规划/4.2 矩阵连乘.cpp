#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
int p[100],m[100][100],s[100][100];
int Left[100],Right[100];//记录答案中输出的左右括号数 

/*
string ans;
int pow(int x,int n)//快速幂 
{
	int base=x,res=1;
	while(n>0)
	{
		if(n&1)
			res*=base;
		n>>=1;
		base*=base;
	}
	return res;
}

string int_to_string(int a)//将整数转换为字符串 
{
	if(a==0) return "0";
	string b;
	int pos=0;
	while(pow(10,pos)<a)
		pos++;
	while(--pos>=0)
	{
		b+=a/pow(10,pos)+'0';
		a%=pow(10,pos);
	}
	return b;
}
*/

void MatrixChain(int p[],int n,int m[][100],int s[][100])
{
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int r=2;r<=n;r++)
	{
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
}

void Traceback(int i,int j,int s[][100])
{
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	//cout<<"Multiply A"<<i<<", "<<s[i][j]<<" and A"<<s[i][j]+1<<", "<<j<<endl;
	if(i<s[i][j])
	{
		Left[i]++;
		Right[s[i][j]]++;
	} 
	if(s[i][j]+1<j)
	{
		Left[s[i][j]+1]++;
		Right[j]++;
	}//加上计算当中的括号 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string str;
	stringstream scin;
	getline(cin,str);
	scin<<str;
	int t,num=-1;
	while(scin>>t)
		p[++num]=t;
	MatrixChain(p,num,m,s);
	cout<<m[1][num]<<endl;//输出最优值答案 
	Traceback(1,num,s);
	cout<<"(";
	for(int i=1;i<=num;i++)
	{
		for(int j=0;j<Left[i];j++)
			cout<<"(";
		cout<<"A"<<i;
		for(int j=0;j<Right[i];j++)
			cout<<")";
	}
	cout<<")"<<endl;//输出最有计算次序 
	return 0;
}
