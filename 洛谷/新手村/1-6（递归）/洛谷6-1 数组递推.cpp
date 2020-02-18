#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,a[1001]={1,1};
	for(i=2;i<=1000;i++)
	{
		if(i%2==0) a[i]=a[i-1]+a[i/2];
		else a[i]=a[i-1];
	}
	cin >> n;
	cout << a[n];
	return 0;
}
