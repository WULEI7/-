#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[100005];
	long long ans=0;
	cin>>n;
	a[0]=-1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1]+1)
			ans+=a[i];
	cout<<ans<<endl;
	return 0; 
}
