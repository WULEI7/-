#include <cstdio>
int main()
{
	int n,a[1005],ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n-1;i++)
		if((a[i-1]>a[i]&&a[i+1]>a[i])||(a[i-1]<a[i]&&a[i+1]<a[i]))
			ans++;
	printf("%d\n",ans);
	return 0;
}
