#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	double w,g,h,r,minn,maxn;
	cin>>t;
	while(t--)
	{
		cin>>w>>g>>h>>r;
		g-=r;
		h-=r;
		minn=sqrt(w*w+(g-h)*(g-h));
		if(g!=0||h!=0)
			maxn=sqrt(g*g+w*g/(g+h)*w*g/(g+h))+sqrt(h*h+w*h/(g+h)*w*h/(g+h));
		else
			maxn=minn;
		printf("%.8f %.8f\n",minn,maxn);
	}
	return 0;
}
