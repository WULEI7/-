#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a[1005],b[1005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int temp=1e9;
		for(int j=0;j<n;j++)
			if(abs(a[i]-b[j])<temp)
				temp=abs(a[i]-b[j]);
		if(temp>ans)
			ans=temp;
	}
	cout<<ans<<endl;
	return 0;
}
