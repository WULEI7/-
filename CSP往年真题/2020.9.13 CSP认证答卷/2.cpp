#include <cstdio>
#include <iostream>
using namespace std;
int n,k,t,x0,y0,x1,y1,jingguo=0,douliu=0;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k>>t>>x0>>y0>>x1>>y1;
	while(n--)
	{
		int temp=0,T=0,flag=0,x,y;
		for(int i=1;i<=t;i++) 
		{
			cin>>x>>y;
			if(x>=x0&&x<=x1&&y>=y0&&y<=y1)
			{
				temp++;
				T++;
				if(T>=k)
					flag=1;
			}
			else
				T=0;
		}
		if(temp>0)
			jingguo++;
		if(flag==1)
			douliu++;
	}
	printf("%d\n%d\n",jingguo,douliu);
	return 0;
}