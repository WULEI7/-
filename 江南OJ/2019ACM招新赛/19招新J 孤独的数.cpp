#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	if(n==1||a[0]!=a[1]) cout<<a[0];
	else
	for(int i=2;i<n;i+=2)
	{
		if(a[i-2]==a[i-1]&&a[i]!=a[i+1])
		{cout<<a[i];break;}
	}
	return 0;
}
