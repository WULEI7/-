#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a[105];
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		m-=a[i];
		ans++;
		if(m<=0) break;
	}
	cout<<ans<<endl;
	return 0;
}
