#include <stdio.h>
double PI=3.14;
int main()
{
	int R;
	double C,S;
	printf("Input a R");
	scanf("%d",&R);
	C=2*PI*R;
	S=PI*R*R;
	printf("周长为%.2f,面积为%.2f\n",C,S);
	return 0;
}
