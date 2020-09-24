#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[105],tot=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	tot/=n;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]!=tot)
		{
			ans++;
			a[i+1]-=(tot-a[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
