#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a[10005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(m--)
		next_permutation(a,a+n);
	printf("%d",a[0]);
	for(int i=1;i<n;i++)
		printf(" %d",a[i]);
	printf("\n");
	return 0;
}
