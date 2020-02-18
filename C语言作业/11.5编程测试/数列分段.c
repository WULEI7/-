#include <stdio.h>
int main()
{
	int n,i,a[1000],s=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		if(a[i]!=a[i-1]) s++;
	}
	printf("%d",s);
	return 0;
}
