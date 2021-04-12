#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	long long a[50];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	long long temp=1,fenzi=0;
	for(int i=0;i<n;i++)
	{
		fenzi+=temp*a[i];
		temp*=2;
	}
	printf("%.9f\n",(double)fenzi/temp);
	return 0;
}
