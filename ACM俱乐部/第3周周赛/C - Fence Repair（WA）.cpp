#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,a[20005],ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
		ans+=a[i]*(n-i);
	ans-=a[0];
	cout<<ans<<endl;
	return 0;
}
