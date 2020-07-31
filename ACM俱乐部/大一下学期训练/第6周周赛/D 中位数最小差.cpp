#include <iostream>
#include <algorithm>
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
		int n,a[200005];
		cin>>n;
		for(int i=0;i<2*n;i++)
			cin>>a[i];
		sort(a,a+2*n);
		cout<<a[n]-a[n-1]<<endl;
	}
	return 0;
}
