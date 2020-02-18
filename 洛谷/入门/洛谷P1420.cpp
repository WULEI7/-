#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	int n,i,j,temp=1,ans=1;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=1;i<n;i++)
	{
		if(a[i]==a[i-1]+1)
		{
			temp++;
			if(temp>ans) ans=temp;
		}
		else temp=1;
	}
	cout << ans;
	return 0;
}
