#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,m,r,c,x,a[1005][1005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	//if(n==1||m==1) while(1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>a[i][j];
	cin>>r>>c>>x;
	int dis=1999999999;
	for(int i=1;i<=m;i++)
	{
		if(a[r][i]==-1) continue;
		int temp=abs(a[r][i]-x);
		if(temp<dis) dis=temp;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][c]==-1) continue;//注意行列下标细节 
		int temp=abs(a[i][c]-x);
		if(temp<dis) dis=temp;
	}
	for(int i=1;i<=m;i++)
	{
		if(a[r][i]==-1) continue;
		int temp=abs(a[r][i]-x);
		if(temp==dis)
			cout<<"("<<r<<":"<<i<<")"<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][c]==-1) continue;
		if(i==r) continue;
		int temp=abs(a[i][c]-x);
		if(temp==dis)
			cout<<"("<<i<<":"<<c<<")"<<endl;
	}
	return 0;
}
