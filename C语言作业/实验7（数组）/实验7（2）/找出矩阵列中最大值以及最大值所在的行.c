#include <stdio.h>
int main()
{
	int a[3][4],max,row,i,j;
	printf("请按顺序输入3行4列矩阵中各行中数据：\n");
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);
	for(j=0;j<4;j++)
	{	
		max=a[0][j];
		row=0;
		for(i=1;i<3;i++)
		{
			if(a[i][j]>max)
			{
				max=a[i][j];
				row=i;
			}
		}
		printf("第%d列第%d行元素%d为最大值\n",j+1,row+1,max);
	}
	return 0;
}
