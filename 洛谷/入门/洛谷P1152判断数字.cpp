#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,a[1000],b[1000],flag=0;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=0;i<n-1;i++)
		b[i]=abs(a[i+1]-a[i]);
	sort(b,b+n-1);
	for(i=1;i<n;i++)
		if(b[i-1]==i) flag++;
	if(flag==n-1) cout << "Jolly";
	else cout << "Not jolly";
	return 0;
}
