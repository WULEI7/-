#include <bits/stdc++.h>
using namespace std;
int n,i,j,flag=0,ans=0,a[10000];
int main()
{
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=0;i<n-1;i++)
	{
		if(a[i+1]<a[i])
			flag=1;
		if(flag==1&&a[i+1]>a[i])
		{ans++;flag=0;}
	}
	cout << ans;
	return 0;
}
