#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a[205],n,N,ans=0;
	cin>>n>>N;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=N;
	for(int i=1;i<=n;i++)
		ans+=i*(a[i+1]-a[i]);
	cout<<ans<<endl;
	return 0;
}