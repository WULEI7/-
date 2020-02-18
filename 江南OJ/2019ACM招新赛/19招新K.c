#include <stdio.h>
int main()
{
	int n,k,a[100],i,s=0,flag=1;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]<=k) s++;
		else break;
	}
	if(s==n) flag=0;
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<=k) s++;
		else break;
	}
	if(flag) printf("%d",s);
	else printf("%d",n);
	return 0;
}
