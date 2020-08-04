#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,x[105][105];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				cin>>x[i][j];
		for(int i=n-1;i>=1;i--)
			for(int j=1;j<=i;j++)
				x[i][j]+=max(x[i+1][j],x[i+1][j+1]);
		cout<<x[1][1]<<endl;
	}
	return 0;
}
