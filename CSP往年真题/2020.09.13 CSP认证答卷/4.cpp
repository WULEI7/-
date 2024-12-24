#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double dis[2005][2005];
struct node
{
	double x,y,z;
}dian[205];
double dot[2005][105];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	double r,x0,y0,z0;
	double zb[105];
	double jiao;
	cin>>n>>m>>r;
	if(n==2)
	{
		cin>>x0>>y0;
		for(int i=1;i<=m;i++)
			cin>>dian[i].x>>dian[i].y;
		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			jiao=acos((pow(dian[i].x-x0,2)+pow(dian[i].y-y0,2)+pow(dian[j].x-x0,2)+pow(dian[j].y-y0,2)-pow(dian[i].x-dian[j].x,2)-pow(dian[i].y-dian[j].y,2))/(2*sqrt(pow(dian[i].x-x0,2)+pow(dian[i].y-y0,2))*sqrt(pow(dian[j].x-x0,2)+pow(dian[j].y-y0,2))));
			dis[i][j]=jiao*r;
		}
		for(int i=1;i<=m;i++)
		{
			double ans=0;
			for(int j=1;j<=m;j++)
			{
				if(j==i) continue;
				ans+=dis[i][j];
			}
			printf("%.14f\n",ans);
		}
	}
	else if(n==3)
	{
		cin>>x0>>y0>>z0;
		for(int i=1;i<=m;i++)
			cin>>dian[i].x>>dian[i].y>>dian[i].z;
		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			jiao=acos((pow(dian[i].x-x0,2)+pow(dian[i].y-y0,2)+pow(dian[i].z-z0,2)+pow(dian[j].x-x0,2)+pow(dian[j].y-y0,2)+pow(dian[j].z-z0,2)-pow(dian[i].x-dian[j].x,2)-pow(dian[i].y-dian[j].y,2)-pow(dian[i].z-dian[j].z,2))/(2*sqrt(pow(dian[i].x-x0,2)+pow(dian[i].y-y0,2)+pow(dian[i].z-z0,2))*sqrt(pow(dian[j].x-x0,2)+pow(dian[j].y-y0,2)+pow(dian[j].z-z0,2))));
			dis[i][j]=jiao*r;
		}
		for(int i=1;i<=m;i++)
		{
			double ans=0;
			for(int j=1;j<=m;j++)
			{
				if(j==i) continue;
				ans+=dis[i][j];
			}
			printf("%.14f\n",ans);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
			cin>>zb[i];
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>dot[i][j];
		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			double temp=0,a=0,b=0;
			for(int k=1;k<=n;k++)
			{
				temp+=pow(dot[i][k]-zb[k],2);
				temp+=pow(dot[j][k]-zb[k],2);
				temp-=pow(dot[i][k]-dot[j][k],2);
				a+=pow(dot[i][k]-zb[k],2);
				b+=pow(dot[j][k]-zb[k],2);
			}
			jiao=acos(temp/2/sqrt(a)/sqrt(b));
			dis[i][j]=jiao*r;
		}
		for(int i=1;i<=m;i++)
		{
			double ans=0;
			for(int j=1;j<=m;j++)
			{
				if(j==i) continue;
				ans+=dis[i][j];
			}
			printf("%.14f\n",ans);
		}
	}
	return 0;
}