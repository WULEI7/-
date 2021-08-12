#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,x,y,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		if(x<y)
			a=x,b=y;
		else
			a=y,b=x;
		double r=(sqrt(5.0)+1)/2;
		double c=(double)(b-a);
		int temp=(int)(r*c);
		if(temp==a)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
