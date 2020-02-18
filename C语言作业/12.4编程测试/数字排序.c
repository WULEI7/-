#include <stdio.h>
int main()
{
	int n,i,j,cd,temp,a[1000],b[1001]={0},c[1001][2];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);//数组a输入数字 
	for(i=0;i<n;i++)
		b[a[i]]++;
	cd=0;
	for(i=0;i<=1000;i++)
		if(b[i]>0) 
		{
			c[cd][0]=i;
			c[cd][1]=b[i];
			cd++;
		}//数组b统计各数字出现的次数 
	for(i=0;i<cd-1;i++)
		for(j=i+1;j<cd;j++)
	{
		if(c[i][1]<c[j][1])
		{
			temp=c[i][0];
			c[i][0]=c[j][0];
			c[j][0]=temp;
			temp=c[i][1];
			c[i][1]=c[j][1];
			c[j][1]=temp;
		}
	}//数组c按照各数字出现次数多少从上往下排序 
	for(i=0;i<cd-1;i++)
		for(j=i+1;j<cd;j++)
	{
		if(c[i][1]==c[j][1]&&c[i][0]>c[j][0])
		{
			temp=c[i][0];
			c[i][0]=c[j][0];
			c[j][0]=temp;
			temp=c[i][1];
			c[i][1]=c[j][1];
			c[j][1]=temp;
		}
	}//数字出现次数相同时，换成数字小的在上大的在下 
	for(i=0;i<cd;i++)
		printf("%d %d\n",c[i][0],c[i][1]);
	return 0;
}
