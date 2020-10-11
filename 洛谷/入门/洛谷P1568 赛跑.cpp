#include <iostream>
#include <cstdio>
using namespace std;
int a[1000005]={0},b[1000005]={0},flag[1000005]={0};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n,v,t,p;
	cin>>m>>n;
	p=0;
	for(int i=0;i<m;i++)
	{
		cin>>v>>t;
		for(int j=1;j<=t;j++)
			a[p+j]=a[p+j-1]+v;
		p+=t;
	}
	if(p+1<=1000000)
		for(int j=p;j<=1000000;j++)
			a[j]=a[j-1];
	p=0;
	for(int i=0;i<n;i++)
	{
		cin>>v>>t;
		for(int j=1;j<=t;j++)
			b[p+j]=b[p+j-1]+v;
		p+=t;
	}
	if(p+1<=1000000)
		for(int j=p+1;j<=1000000;j++)
			b[j]=b[j-1];
	int cnt=0;
	for(int i=1;i<=1000000;i++)
	{
		if(a[i]>b[i])
			flag[i]=1;
		else if(a[i]<b[i])
			flag[i]=2;
		else if(a[i]==b[i])
			flag[i]=flag[i-1];
		if(i>=2&&flag[i-1]!=0&&flag[i]!=flag[i-1])
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
