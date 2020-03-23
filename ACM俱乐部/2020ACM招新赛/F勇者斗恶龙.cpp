#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,a[100],b[100],ans=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	for(i=0;i<n;i++)
		ans+=a[i]*b[i];
	cout<<ans;
	return 0;
}
