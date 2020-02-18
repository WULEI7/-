#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,sum=0,tot=0,a[100000];
	cin >> n >> m;
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=0;i<n;i++)
	{
		if(sum+a[i]>m)
		{
			tot++;
			sum=0;
		}
		sum+=a[i];
	}
	if(sum>0) tot++;
	cout << tot;
	return 0;
}
