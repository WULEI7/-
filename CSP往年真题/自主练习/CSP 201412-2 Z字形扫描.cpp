#include <cstdio>
int n,a[505][505];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	int x=1,y=1,flag=1;
	printf("%d",a[1][1]);
	while(1)
	{
		if(x==n&&y==n) break;
		if(flag==1)
		{
			if(y+1<=n)
				printf(" %d",a[x][++y]);
			else
				printf(" %d",a[++x][y]);
			if(x==n&&y==n) break;
			x++;y--;
			while(y>=1&&x<=n)
				printf(" %d",a[x++][y--]);
			flag=2;
			x--;y++;
			continue;
		}
		if(flag==2)
		{
			if(x+1<=n)
				printf(" %d",a[++x][y]);
			else
				printf(" %d",a[x][++y]);
			if(x==n&&y==n) break;
			x--;y++;
			while(x>=1&&y<=n)
				printf(" %d",a[x--][y++]);
			flag=1;
			x++;y--;
			continue;
		}
	}
	printf("\n");
	return 0;
}
