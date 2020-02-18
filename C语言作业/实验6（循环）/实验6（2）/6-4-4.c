#include <stdio.h>
int main()
{
	int n,m,i,k,d,x,c,t=0;
	float a;
	printf("Please input student's number:\n");
	scanf("%d",&n);
	printf("Student CJ number is:\n");
	scanf("%d",&m);
	for(i=1;i<=n;i++){
		printf("Please input XH of No %d:\n",i);
		scanf("%d",&x);
		printf("Please input CJ of No %d:\n",i);
		for(k=1;k<=m;k++){
			scanf("%d",&d);
			t+=d;}
		a=(float)t/m;
		printf("Student No %d's Total CJ is %d,Avg CJ is %.1f\n",x,t,a);
		t=0;
		}
	return 0;
}
