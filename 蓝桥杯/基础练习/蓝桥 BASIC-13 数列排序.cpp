#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,a[205];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	printf("%d",a[0]);
	for(int i=1;i<n;i++)
		printf(" %d",a[i]);
	printf("\n");
	return 0;
}
