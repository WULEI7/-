#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct node
{
	int A,B;
}dis[1005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int p,d,cnt=0,cnta=0,cntb=0;
	double ans;
	cin>>p>>d;
	while(p--)
	{
		int a,b,t;
		cin>>t>>a>>b;
		dis[t].A+=a;
		dis[t].B+=b;
	}
	for(int i=1;i<=d;i++)
	{
		int tot,win,ta,tb,wa,wb;
		ta=dis[i].A;
		tb=dis[i].B;
		tot=ta+tb;
		cnt+=tot;
		win=(tot+2)/2;
		if(ta>tb)
		{
			wa=ta-win;
			wb=tb;
			printf("A %d %d\n",wa,wb);
		}
		else
		{
			wa=ta;
			wb=tb-win;
			printf("B %d %d\n",wa,wb);
		}
		cnta+=wa;
		cntb+=wb;
	}
	ans=fabs(cnta-cntb)/cnt;
	printf("%.10f\n",ans);
	return 0;
}
