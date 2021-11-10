#include <iostream>
#include <cstdio>
using namespace std;
int n,a[105],ans=0,res=0;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
		if(a[i]==a[i-1])
			res+=a[i];
	}
	cout<<ans<<endl<<ans-res<<endl;
	return 0; 
}
