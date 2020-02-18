#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,a[1000];
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	cout << a[0];
	return 0;
}
