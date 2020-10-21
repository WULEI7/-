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
	int pos=n;
	for(int i=0;i<n;i++)
	{
		if(c[i]<=0)
		{
			int t=upper_bound(c+i,c+n,-c[i])-c;
			if(t<n)
				cnt+=n-t;
		}
		else
		{
			pos=i;
			break;
		}
	}
	long long s=n-pos;//×¢Òâlong long 
	cnt+=s*(s-1)/2;
	cout<<cnt<<endl;
	return 0;
}
