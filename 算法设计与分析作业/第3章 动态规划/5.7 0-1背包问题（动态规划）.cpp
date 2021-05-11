#include <iostream>
#include <cstdio>
using namespace std;
int c,n,v[1000],w[1000],x[1000],m[1000][1000];
void Knapsack(int v[],int w[],int c,int n,int m[][1000])
{
	int jmax=min(w[n]-1,c);
	for(int j=0;j<=jmax;j++)
		m[n][j]=0;
	for(int j=w[n];j<=c;j++)
		m[n][j]=v[n];
	for(int i=n-1;i>1;i--)
	{
		jmax=min(w[i]-1,c);
		for(int j=0;j<=jmax;j++)
			m[i][j]=m[i+1][j];
		for(int j=w[i];j<=c;j++)
			m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
	}
	m[1][c]=m[2][c];
	if(c>=w[1])
		m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}
void Traceback(int m[][1000],int w[],int c,int n,int x[])
{
	for(int i=1;i<n;i++)
	{
		if(m[i][c]==m[i+1][c])
			x[i]=0;
		else
		{
			x[i]=1;
			c-=w[i];
		}
	}
	x[n]=m[n][c]?1:0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=1;i<=n;i++)
		cin>>w[i];
	Knapsack(v,w,c,n,m);
	Traceback(m,w,c,n,x);
	cout<<m[1][c]<<endl;
	for(int i=1;i<=n;i++)
		if(x[i]==1)
			cout<<i<<" ";
	cout<<endl;
	return 0;
}
