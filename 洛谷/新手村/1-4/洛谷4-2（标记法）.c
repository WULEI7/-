#include <stdio.h>
int main()
{
	int L,M,i,j,s=0,a[100][2],b[10001]={0};
	scanf("%d %d",&L,&M);
	for(i=0;i<M;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<M;i++)
		for(j=a[i][0];j<=a[i][1];j++)
			b[j]=1;
	for(i=0;i<=L;i++)
		if(b[i]==0) s++;
	printf("%d",s);
	return 0;
}
