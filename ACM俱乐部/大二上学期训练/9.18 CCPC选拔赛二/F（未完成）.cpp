#include <iostream>
#include <cstdio>
using namespace std;
int a[505][505],umax[505][505],dmax[505][505],umin[505][505],dmin[505][505],lmax[505][505],rmax[505][505],lmin[505][505],rmin[505][505];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,m;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<505;i++)
		for(int j=0;j<505;j++)
		{
			umin[i][j]=1999999999;
			dmin[i][j]=1999999999;
			lmin[i][j]=1999999999;
			rmin[i][j]=1999999999;
			umax[i][j]=0;
			dmax[i][j]=0;
			lmax[i][j]=0;
			rmax[i][j]=0;
		}
		cin>>n>>m;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
		for(int j=0;j<n;j++)
		{
			int maxn=0,minn=1999999999;
			for(int i=0;i<m;i++)
			{
				if(a[i][j]>maxn) maxn=a[i][j];
				if(a[i][j]<minn) minn=a[i][j];
				umax[i][j]=maxn;
				umin[i][j]=minn;
			}
		}
		for(int j=0;j<n;j++)
		{
			int maxn=0,minn=1999999999;
			for(int i=m-1;i>=0;i--)
			{
				if(a[i][j]>maxn) maxn=a[i][j];
				if(a[i][j]<minn) minn=a[i][j];
				dmax[i][j]=maxn;
				dmin[i][j]=minn;
			}
		}
		for(int i=0;i<n;i++)
		{
			int maxn=0,minn=1999999999;
			for(int j=0;j<m;j++)
			{
				if(umax[i][j]>maxn) maxn=umax[i][j];
				if(umax[i][j]<minn) minn=umax[i][j];
				lmax[i][j]=maxn;
				lmin[i][j]=minn;
			}
		}
		for(int i=0;i<n;i++)
		{
			int maxn=0,minn=1999999999;
			for(int j=m-1;j>=0;j--)
			{
				if(dmax[i][j]>maxn) maxn=dmax[i][j];
				if(dmax[i][j]<minn) minn=dmax[i][j];
				rmax[i][j]=maxn;
				rmin[i][j]=minn;
			}
		}
		
		int minmax=1999999999;
		for(int i=2;i<n-1;i++)
		for(int j=2;j<m-1;j++)
		{
			int max1,max2,max3,max4,min1,min2,min3,min4;
			max1=lmax[i-1][j-1];
			
			
		}
	}
	return 0;
}
