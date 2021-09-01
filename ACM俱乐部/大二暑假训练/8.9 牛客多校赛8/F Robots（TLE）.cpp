#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char g[505][505];
int dp[505][505];
int main()
{
	int n,m,q,t,x1,y1,x2,y2;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>g[i][j];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		if(x1>x2||y1>y2)
		{
			printf("no\n");
			continue;
		}
		if(t==1)
		{
			if(y1!=y2)
			{
				printf("no\n");
				continue;
			}
			int flag=1;
			for(int i=x1;i<=x2;i++)
				if(g[i][y1]=='1')
				{
					flag=0;
					break;
				}
			if(flag==0)
			{
				printf("no\n");
				continue;
			}
			printf("yes\n");
		}
		else if(t==2)
		{
			if(x1!=x2)
			{
				printf("no\n");
				continue;
			}
			int flag=1;
			for(int i=y1;i<=y2;i++)
				if(g[x1][i]=='1')
				{
					flag=0;
					break;
				}
			if(flag==0)
			{
				printf("no\n");
				continue;
			}
			printf("yes\n");
		}
		else
		{
			memset(dp,0,sizeof(dp));
			dp[x1][y1]=1;
			for(int i=x1;i<=x2;i++)
			{
				if(g[i][y1]=='0')
					dp[i][y1]=1;
				else
					break;
			}
			for(int i=y1;i<=y2;i++)
			{
				if(g[x1][i]=='0')
					dp[x1][i]=1;
				else
					break;
			}
			for(int i=x1+1;i<=x2;i++)
			for(int j=y1+1;j<=y2;j++)
			{
				if(dp[i-1][j]==0&&dp[i][j-1]==0||g[i][j]=='1')
					dp[i][j]=0;
				else
					dp[i][j]=1;
			}
			if(dp[x2][y2]==1)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0; 
}
