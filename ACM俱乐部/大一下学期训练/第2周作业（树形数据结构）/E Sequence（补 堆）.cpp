#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[2005],b[2005],sum[2005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for(int c=1;c<m;c++)
		{
			for(int i=0;i<n;i++)
				cin>>b[i];
			sort(b,b+n);
			for(int i=0;i<n;i++)
				sum[i]=a[0]+b[i];
			make_heap(sum,sum+n);
			for(int i=1;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int temp=a[i]+b[j];
				if(temp>sum[0]) break;
				pop_heap(sum,sum+n);
				sum[n-1]=temp;
				push_heap(sum,sum+n);
			}
			for(int i=0;i<n;i++)
				a[i]=sum[i];
		}
		sort(a,a+n);
		cout<<a[0];
		for(int i=1;i<n;i++)
			cout<<" "<<a[i];
		cout<<endl;
	}
	return 0;
}
