#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
using namespace std;
int a[310][310],r[310][310],c[310][310];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,k,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		memset(a,0,sizeof(a));
		int x=1,y=1,cnt=1;
		for(int i=1;i<=k;i++)
		{
			a[x++][y++]=1;
			if(x>n)
			{
				x=1;
				cnt++;
				y=cnt;
			}
			if(y>n)
				y=1;
		}//贪心构造矩阵 
		int rmax=0,rmin=999,cmax=0,cmin=999;
		for(int i=1;i<=n;i++)
		{
			r[i][1]=a[i][1];
			for(int j=2;j<=n;j++)
				r[i][j]=r[i][j-1]+a[i][j];
		}//行的前缀和 
		for(int j=1;j<=n;j++)
		{
			c[1][j]=a[1][j];
			for(int i=2;i<=n;i++)
				c[i][j]=c[i-1][j]+a[i][j];
		}//列的前缀和 
		for(int i=1;i<=n;i++)
		{
			rmax=max(rmax,r[i][n]);
			rmin=min(rmin,r[i][n]);
		}
		for(int j=1;j<=n;j++)
		{
			cmax=max(cmax,c[n][j]);
			cmin=min(cmin,c[n][j]);
		}
		ans=(rmax-rmin)*(rmax-rmin)+(cmax-cmin)*(cmax-cmin);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
