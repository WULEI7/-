#include <cstdio>
#include <iostream>
using namespace std; 
int a[1001];
int main()
{
	int t,n,m,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			ans+=a[i];
		}
		if(ans<m) cout<<ans<<endl;
		else cout<<m<<endl;
	}
	return 0;
}
