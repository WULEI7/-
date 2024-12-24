#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[100005],b[100005],c[100005],w[100005];
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int k=1;k<=n;k++)
	{
		int t=b[k];
		b[k]=0;
		int maxn=0;
		for(int i=0;i<=n+1;i++)
			c[i]=0;
		for(int i=0;i<=n;i++)
		{
			c[i+1]=c[i]+a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n+1;j++)
				c[j]-=b[i];
		}
		for(int i=1;i<=n+1;i++)
		{
			//cout<<c[i]<<" ";
			if(c[i]>maxn)
				maxn=c[i];
		}
		cout<<maxn<<" ";
		b[k]=t;
	}
	return 0;
}
