#include <bits/stdc++.h>
#define eps 1e-10
using namespace std;
const int maxn=5005;
int sgn(double x)
{
	if(fabs(x)<eps)
		return 0;
	else
		return x<0?-1:1;
}
struct Point
{
	double x,y;
}Z[maxn],X[maxn],Y[maxn];
double Distance(Point a,Point b)
{
	return hypot(a.x-b.x,a.y-b.y);
}
Point circle_center(const Point a,const Point b,const Point c)//求三角形abc的外接圆的圆心 
{
	Point center;
	double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
	double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
	double d=a1*b2-a2*b1;
	center.x=a.x+(c1*b2-c2*b1)/d;
	center.y=a.y+(a1*c2-a2*c1)/d;
	return center; 
}
void min_cover_circle(Point *p,int n,Point &c,double &r)//求最小覆盖圆，返回圆心c、半径r 
{
	random_shuffle(p,p+n);
	c=p[0],r=0;
	for(int i=1;i<n;i++)
	{
		if(sgn(Distance(p[i],c)-r)>0)
		{
			c=p[i],r=0;
			for(int j=0;j<i;j++)
			{
				if(sgn(Distance(p[j],c)-r)>0)
				{
					c.x=(p[i].x+p[j].x)/2;
					c.y=(p[i].y+p[j].y)/2;
					r=Distance(p[j],c);
					for(int k=0;k<j;k++)
					{
						if(sgn(Distance(p[k],c)-r)>0)
						{
							c=circle_center(p[i],p[j],p[k]);
							r=Distance(p[i],c);
						}
					}
				}
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	double a,b,c,ans1,ans2,ans3;
	Point p1,p2,p3;
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		Z[i].x=a,Z[i].y=b;
		X[i].x=b,X[i].y=c;
		Y[i].x=a,Y[i].y=c;
	}
	min_cover_circle(Z,n,p1,ans1);
	min_cover_circle(X,n,p2,ans2);
	min_cover_circle(Y,n,p3,ans3);
	ans1*=2,ans2*=2,ans3*=2;
	if(ans1<ans2)
		ans2=ans1;
	if(ans2<ans3)
		ans3=ans2;
	printf("%.10f\n",ans3);
	return 0;
}
