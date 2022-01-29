#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,l,r,tot,a[100005],dis[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		dis[i+1]=dis[i]+a[i];
	}
	tot=dis[m+1];
	cin>>n;
	while(n--)
	{
		cin>>l>>r;
		if(l>r) swap(l,r);
		cout<<min(dis[r]-dis[l],tot-(dis[r]-dis[l]))<<endl;
	}
	return 0;
}
