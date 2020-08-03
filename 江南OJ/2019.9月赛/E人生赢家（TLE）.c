#include <stdio.h>
int main()
{
	int n,m,i,j,a[100000][2],b[100000],max=0,t=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d %d",&a[i][0],&a[i][1]);
	for(i=0;i<m;i++)
		for(j=a[i][0]-1;j<=a[i][1]-1;j++)
			b[j]=1;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(b[j]==0) t++;
			else break;
		}
		if(t>max) max=t;
		t=0;
	}
	printf("%d",max);
	return 0;
}
