#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n,a[200005],b[200005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=0;
		}
		int j=n-1;
		for(int i=n-1;i>=0;i--)
		{
			j=min(i,j);
			while(j>i-a[i]&&j>=0)
				b[j--]=1;
		}
		for(int i=0;i<n;i++)
			printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}
