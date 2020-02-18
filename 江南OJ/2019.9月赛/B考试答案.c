#include <stdio.h>
int main()
{
	int a[4],b[4],n,t=0,i;
	scanf("%d",&n);
	for(i=0;i<=3;i++) scanf("%d",&a[i]);
	for(i=0;i<=3;i++) scanf("%d",&b[i]);
	for(i=0;i<=3;i++)
	{
		if(a[i]<=b[i]) t+=a[i];
		else t+=b[i];
	}
	printf("%d",t);
	return 0;
}
