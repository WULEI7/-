#include <stdio.h>
int sum(int a,int b,int c,int d)
{
	int jf,yw,x;
	if(a==1) x=0;
	if(a==3||a==5|a==9|a==17) {jf=1;yw=1;}
	if(a==5||a==7||a==13||a==19) {jf=2;yw=2;} 
	if(a==15) {jf=3;yw=3;}
	if(a==2||a==4||a==8||a==16) {jf=0;yw=1;}
	if(a==6||a==10||a==12||a==18||a==20) {jf=1;yw=2;}
	if(a==14) {jf=2;yw=3;}
	if(yw*c+jf*d>=b) x=b;
	else x=yw*c+jf*d;
	return x;
}
int main()
{
	int n,i,j,a[20][4];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		printf("%d\n",sum(a[i][0],a[i][1],a[i][2],a[i][3]));
	return 0;
}
