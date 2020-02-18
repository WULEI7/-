#include <stdio.h>
int main()
{
	int n,k,i,j,wz,temp,a[10000];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		wz=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[wz])
				wz=j;
		temp=a[i];
		a[i]=a[wz];
		a[wz]=temp;
	}
	for(i=1;i<n;i++)
		if(a[i]==a[i-1])
		{
			for(j=i;j<n;j++)
				a[j]=a[j+1];
			i--;
			n--;
		}
	if(k<=n) printf("%d",a[k-1]);
	else printf("NO RESULT");
	return 0;
}
