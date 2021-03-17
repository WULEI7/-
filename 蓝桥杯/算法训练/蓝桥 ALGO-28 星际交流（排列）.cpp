#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t,a[10005];
	cin>>n>>t;
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(t--)
		next_permutation(a,a+n);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
