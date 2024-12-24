#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,N;
long long ans=0,a[100005],f[100005],g;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>N;
	long long r=N/(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=a[i-1];j<a[i];j++)
			f[j]=i-1;
	}
	for(int j=a[n];j<N;j++)
		f[j]=n;
	for(int i=1;i<N;i++)
	{
		g=i/r;
		ans+=abs(f[i]-g);
	}
	cout<<ans<<endl;
	return 0;
}