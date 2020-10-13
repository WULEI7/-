#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[15005],b[15005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	ans=a[n-1]-a[0]+m;
	for(int i=0;i<n-1;i++)
		b[i]=a[i+1]-a[i];
	sort(b,b+n-1,cmp);
	for(int i=0;i<m-1;i++)
		ans-=b[i];
	cout<<ans<<endl;
	return 0;
}
