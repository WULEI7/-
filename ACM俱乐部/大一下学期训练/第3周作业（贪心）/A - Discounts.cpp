#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[300005],b[300005];
int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	long long tot=0;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	sort(a+1,a+m+1);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		cout<<tot-a[m-b[i]+1]<<endl;
	return 0;
}
