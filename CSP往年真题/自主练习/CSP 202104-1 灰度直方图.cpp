#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,m,L,a[505][505],cnt[260];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>L;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		cin>>a[i][j];
		cnt[a[i][j]]++;
	}
	for(int i=0;i<L;i++)
		cout<<cnt[i]<<" ";
	cout<<endl;
	return 0;
}
