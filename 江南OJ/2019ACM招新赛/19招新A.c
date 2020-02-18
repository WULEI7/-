#include <stdio.h>
int main()
{
	int a[2][3],i,j;
	float x,y,D,D1,D2;
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	D=a[0][0]*a[1][1]-a[0][1]*a[1][0];
	D1=a[0][2]*a[1][1]-a[0][1]*a[1][2];
	D2=a[0][0]*a[1][2]-a[0][2]*a[1][0];
	x=D1/D;
	y=D2/D;
	printf("%.3f %.3f",x,y);
	return 0;
}
