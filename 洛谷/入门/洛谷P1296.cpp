#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	int i,j,n,d,ans=0;
	cin >> n >> d;
	for(i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[j]-a[i]<=d) ans++;
			else break;
		}
	cout << ans;
}
