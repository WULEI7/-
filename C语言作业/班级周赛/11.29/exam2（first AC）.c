#include <stdio.h>
int main()
{
	int b[81][80]={0},a,c,n,i,j,wz;
	scanf("%d %d",&a,&n);
	for(i=0;i<n;i++)
		for(j=79;j>=80+i-n;j--)
			b[i][j]=a;
	for(j=79;j>=0;j --)
	{
		c=b[0][j];
		for(i=1;i<n;i++)
		{
			c-=b[i][j];
			if(c<0)
			{
				b[0][j-1]-=1;
				c+=10;
			}
		}
		b[80][j]=c;
	}
	for(j=0;j<80;j++)
		if(b[80][j]!=0)
		{
			wz=j;break;
		}
	for(j=wz;j<80;j++)
		printf("%d",b[80][j]);
	return 0;
}
