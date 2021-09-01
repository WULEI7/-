#include <iostream>
#include <cstdio>
using namespace std;
long long a[24]={1,2,4,5,7,8,11,14,17,22,25,28,41,44,47,52,55,58,71,74,77,82,85,88};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	long long l,r;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>l>>r;
		long long ans=r-l+1;
		for(int j=0;j<24;j++)
			if(a[j]>=l&&a[j]<=r)
				ans--;
		cout<<ans<<endl;
	}
	return 0;
}
