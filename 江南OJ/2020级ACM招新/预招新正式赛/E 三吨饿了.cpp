#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[105][105];
int x[10005],y[10005],cnt=0;
int tx[8]={-1,-1,-1,0,0,1,1,1};
int ty[8]={-1,0,1,-1,1,-1,0,1};
int check(int x,int y)
{
	for(int i=0;i<8;i++)
		if(x+tx[i]>=1&&x+tx[i]<=n&&y+ty[i]>=1&&y+ty[i]<=m&&a[x+tx[i]][y+ty[i]]!=0)
			return 0;//座位不满足四周没人的要求 
	int flag=0;
	for(int i=x-2;i>=1;i--)
		if(a[i][y]!=0)
		{
			if(a[i][y]==3)
				flag++;
			break;
		}
	for(int i=x+2;i<=n;i++)
		if(a[i][y]!=0)
		{
			if(a[i][y]==1)
				flag++;
			break;
		}
	for(int i=y-2;i>=1;i--)
		if(a[x][i]!=0)
		{
			if(a[x][i]==2)
				flag++;
			break;
		}
	for(int i=y+2;i<=m;i++)
		if(a[x][i]!=0)
		{
			if(a[x][i]==4)
				flag++;
			break;
		}
	if(flag<4) return 1;//至少有一种朝向可以坐 
	return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>a[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(check(i,j)==1)
		{
			x[cnt]=i;
			y[cnt]=j;
			cnt++;
		}
	if(cnt==0)
		printf("-1\n");
	else
	{
		for(int i=0;i<cnt;i++)
			printf("%d %d\n",x[i],y[i]);
	}
	return 0;
}
