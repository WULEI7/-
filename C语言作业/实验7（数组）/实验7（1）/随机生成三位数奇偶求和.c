#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 20
int main()
{
	int i,a[n],even[n],odd[n];
	int even_n=0,even_sum=0,odd_n=0,odd_sum=0;
	srand((unsigned)time(NULL));
	printf("������ɵ�%d��3λ��Ȼ�����£�\n",n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%900+100;
		printf("%d\t",a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			even[even_n]=a[i];
			even_n++;
			even_sum+=a[i];
		}
		else
		{
			odd[odd_n]=a[i];
			odd_n++;
			odd_sum+=a[i];
		}
	}
	printf("\n����ż��֮��%d������֮��%d",even_sum,odd_sum);
	printf("\n����ż����%d�������£�\n",even_n);
	for(i=0;i<even_n;i++)
		printf("%4d",even[i]);
	printf("\n����������%d�������£�\n",odd_n);
	for(i=0;i<odd_n;i++)
		printf("%4d",odd[i]);
	return 0;
}
