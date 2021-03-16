#include <iostream>
#include <cstdio>
#include <cmath> 
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t=1;
	double x0,y0,x1,x2,y1,y2,r,jiao,dis1,dis2,po[15][15];
	while(cin>>x0>>y0>>x1>>y1>>x2>>y2)
	{
		if(x0==0&&y0==0&&x1==0&&y1==0&&x2==0&&y2==0) break;
		r=sqrt(pow(x1-x0,2)+pow(y1-y0,2));
		jiao=acos((pow(x1-x0,2)+pow(y1-y0,2)+pow(x2-x0,2)+pow(y2-y0,2)-pow(x1-x2,2)-pow(y1-y2,2))/(2*sqrt(pow(x1-x0,2)+pow(y1-y0,2))*sqrt(pow(x2-x0,2)+pow(y2-y0,2))));
		dis1=jiao*r;
		cin>>n;
		po[0][0]=x1,po[0][1]=y1;
		for(int i=1;i<=n;i++)
			cin>>po[i][0]>>po[i][1];
		po[n+1][0]=x2,po[n+1][1]=y2;
		dis2=0;
		for(int i=1;i<=n+1;i++)
			dis2+=sqrt(pow(po[i][0]-po[i-1][0],2)+pow(po[i][1]-po[i-1][1],2));
		if(dis1<dis2)
			printf("Case #%d: Stick to the Circle.\n\n",t);
		else
			printf("Case #%d: Watch out for squirrels!\n\n",t);
		t++;
	}
	return 0;
}
