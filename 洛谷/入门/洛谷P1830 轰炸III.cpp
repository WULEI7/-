#include <iostream>
#include <cstdio>
using namespace std;
int mp[105][105][2]={0};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,x,y,x0,y0,x1,y1,x2,y2;
	cin>>n>>m>>x>>y;
	for(int k=1;k<=x;k++)
	{
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
		{
			mp[i][j][0]++;
			mp[i][j][1]=k;
		}
	}
	while(y--)
	{
		cin>>x0>>y0;
		if(mp[x0][y0][0]==0)
			printf("N\n");
		else
			printf("Y %d %d\n",mp[x0][y0][0],mp[x0][y0][1]);
	}
	return 0;
}
