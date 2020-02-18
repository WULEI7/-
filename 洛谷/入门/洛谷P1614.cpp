#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,m,ans=0,temp,a[3000];
	cin >> n >> m;
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=0;i<m;i++)
		ans+=a[i];
	temp=ans;
	for(i=m;i<n;i++)
	{
		temp=temp+a[i]-a[i-m];
		if(temp<ans) ans=temp;
	}
	cout << ans;
	return 0;
}
