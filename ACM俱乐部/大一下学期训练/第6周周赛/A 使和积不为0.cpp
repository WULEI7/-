#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,sum=0,zero=0,ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			sum+=a;
			if(a==0) zero++;
		}
		ans+=zero;
		if(sum+zero==0) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
