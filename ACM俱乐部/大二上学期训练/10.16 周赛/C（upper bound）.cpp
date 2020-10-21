#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005],b[200005],c[200005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
		c[i]=a[i]-b[i];
	sort(c,c+n);
	long long cnt=0;
	for(int i=0;i<n;i++)
	{
		int t=upper_bound(c+i+1,c+n,-c[i])-c;
		if(t<n)
			cnt+=n-t;
	}
	cout<<cnt<<endl;
	return 0;
}
