#include <stdio.h>
int main()
{
	int n,k,i,a[1000],b=0,c,s=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c+=a[i];
	}
	for(i=0;i<n;i++)
	{
		b+=a[i];
		if(b>=k)
		{
			s++;
			c-=b;
			b=0;
		}
	}
	if(c>0) s++;
	printf("%d",s);
	return 0;
}
