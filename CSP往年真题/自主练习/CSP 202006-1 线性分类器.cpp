#include <cstdio>
#include <iostream>
using namespace std;
int a[1005][2],b[1005][2];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,x,y,e,f,g,ta=0,tb=0;
	char c;
	cin>>n>>m;
	while(n--)
	{
		cin>>x>>y>>c;
		if(c=='A')
		{
			a[ta][0]=x;
			a[ta][1]=y;
			ta++;
		}
		else if(c=='B')
		{
			b[tb][0]=x;
			b[tb][1]=y;
			tb++;
		}
	}
	while(m--)
	{
		cin>>e>>f>>g;
		int flag=1;
		if(e+f*a[0][0]+g*a[0][1]>0)
		{
			for(int i=0;i<ta;i++)
			{
				if(e+f*a[i][0]+g*a[i][1]<0)
				{
					flag=0;
					break;
				}
			}
			for(int i=0;i<tb;i++)
			{
				if(e+f*b[i][0]+g*b[i][1]>0)
				{
					flag=0;
					break;
				}
			}
		}
		else if(e+f*a[0][0]+g*a[0][1]<0)
		{
			for(int i=0;i<ta;i++)
			{
				if(e+f*a[i][0]+g*a[i][1]>0)
				{
					flag=0;
					break;
				}
			}
			for(int i=0;i<tb;i++)
			{
				if(e+f*b[i][0]+g*b[i][1]<0)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
