#include <stdio.h>
int main()
{
	int n,i[10],sum=0,j,k,a[8953][10];
	scanf("%d",&n);
	if(n<10||n>30) printf("0");
	else
	{
		for(i[0]=1;i[0]<=3;i[0]++)
		for(i[1]=1;i[1]<=3;i[1]++)
		for(i[2]=1;i[2]<=3;i[2]++)
		for(i[3]=1;i[3]<=3;i[3]++)
		for(i[4]=1;i[4]<=3;i[4]++)
		for(i[5]=1;i[5]<=3;i[5]++)
		for(i[6]=1;i[6]<=3;i[6]++)
		for(i[7]=1;i[7]<=3;i[7]++)
		for(i[8]=1;i[8]<=3;i[8]++)
		for(i[9]=1;i[9]<=3;i[9]++)
			if(i[0]+i[1]+i[2]+i[3]+i[4]+i[5]+i[6]+i[7]+i[8]+i[9]==n)
			{
				for(j=0;j<10;j++)
					a[sum][j]=i[j];
				sum++;
			}
		printf("%d\n",sum);
		for(k=0;k<sum;k++)
		{
			for(j=0;j<10;j++)
				printf("%d ",a[k][j]);
			printf("\n");
		}
	}
	return 0;
}
