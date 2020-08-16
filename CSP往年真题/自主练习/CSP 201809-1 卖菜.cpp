#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,a[1005],b[1005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	b[0]=(a[0]+a[1])/2;
	b[n-1]=(a[n-2]+a[n-1])/2;
	for(int i=1;i<n-1;i++)
		b[i]=(a[i-1]+a[i]+a[i+1])/3;
	printf("%d",b[0]);
	for(int i=1;i<n;i++)
		printf(" %d",b[i]);
	return 0;
}
