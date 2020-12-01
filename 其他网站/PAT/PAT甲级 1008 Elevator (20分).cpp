#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[105],ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	ans+=a[0]*6+5;
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
			ans+=(a[i]-a[i-1])*6+5;
		else
			ans+=(a[i-1]-a[i])*4+5;
	}
	cout<<ans<<endl;
	return 0; 
}
