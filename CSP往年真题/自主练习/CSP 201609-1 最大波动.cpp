#include <cstdio>
#include <cmath>
#include <algorithm>
int main()
{
	int n,a[1005],ans=0;
	scanf("%d%d",&n,&a[0]);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		int t=abs(a[i]-a[i-1]);
		if(t>ans) ans=t;
	}
	printf("%d\n",ans);
	return 0;
}
