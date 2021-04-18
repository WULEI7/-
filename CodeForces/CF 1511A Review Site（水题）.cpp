#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			if(a==1||a==3)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
