#include <stdio.h>
#define n 5  
int main()
{      
    int a[n][n],i,j;
    int sum1=0,sum2=0;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&a[i][j]);
	printf("生成的5阶矩阵如下：\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%10d",a[i][j]);
		printf("\n");
	}
    for(i=0;i<n;i++)
        sum1=sum1+a[i][i];
    for(i=0;i<n;i++)
        sum2=sum2+a[i][4-i];
    printf("主对角线元素之和%d\n",sum1);
    printf("副对角线元素之和%d\n",sum2);
    return 0;
}
