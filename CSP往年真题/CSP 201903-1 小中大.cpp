#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[100005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	if(n%2)
		printf("%d %d %d",a[n-1],a[n/2],a[0]);
	else
	{
		if((float)(a[n/2-1]+a[n/2])/2==(a[n/2-1]+a[n/2])/2)
			printf("%d %d %d",a[n-1],(a[n/2-1]+a[n/2])/2,a[0]);
		else
			printf("%d %.1f %d",a[n-1],(float)(a[n/2-1]+a[n/2])/2,a[0]);
	}
	return 0;
}
