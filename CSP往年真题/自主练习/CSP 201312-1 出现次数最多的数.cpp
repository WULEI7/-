#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,a[1005];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int ans=a[0],cnt=1,temp=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
			temp++;
		else
			temp=1;
		if(temp>cnt)
		{
			cnt=temp;
			ans=a[i];
		}
	}
	printf("%d",ans);
	return 0;
}
