#include <cstdio>
int main()
{
	int a[5]={0};
	for(a[0]=0;a[0]<=1;a[0]++)
	for(a[1]=0;a[1]<=1;a[1]++)
	for(a[2]=0;a[2]<=1;a[2]++)
	for(a[3]=0;a[3]<=1;a[3]++)
	for(a[4]=0;a[4]<=1;a[4]++)
	{
		for(int i=0;i<5;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
