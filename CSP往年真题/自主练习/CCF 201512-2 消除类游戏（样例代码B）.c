#include <stdio.h>
int main()
{
	int n,m,i,j,qipan[35][35],biaoji[35][35]={0};
	//qipan数组用来输入各棋子的颜色，另外用一个biaoji数组来标记棋盘上每个位置是否会被消除，所有元素初始化为0 
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&qipan[i][j]);//输入各棋子颜色编号 
	for(i=1;i<=n;i++)
		for(j=1;j<=m-2;j++)
			if(qipan[i][j]==qipan[i][j+1]&&qipan[i][j]==qipan[i][j+2])
				biaoji[i][j]=biaoji[i][j+1]=biaoji[i][j+2]=1;
	//判断每一行（从左到右）是否有连续三个（或更多）颜色相同的棋子，若有，将biaoji数组中对应位置元素全部标记为1 
	for(j=1;j<=m;j++)
		for(i=1;i<=n-2;i++)
			if(qipan[i][j]==qipan[i+1][j]&&qipan[i][j]==qipan[i+2][j])
				biaoji[i][j]=biaoji[i+1][j]=biaoji[i+2][j]=1;
	//判断每一列（从上到下）是否有连续三个（或更多）颜色相同的棋子，若有，将biaoji数组中对应位置元素全部标记为1 
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(biaoji[i][j]==1)
				qipan[i][j]=0;//遍历biaoji数组，如果有标记为1，则将qipan数组对应位置元素改为0 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%d",qipan[i][j]);
			if(j<m) printf(" ");
		}
		printf("\n");
	}//按行列顺序输出qipan数组，空格和换行的输出尽量严谨 
	return 0;
}
