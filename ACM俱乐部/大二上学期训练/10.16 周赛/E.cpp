#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
	int x,y;
}p[100005];
bool cmp(point a,point b)
{
	return a.x==b.x ? a.y<b.y : a.x<b.x;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,flag=1;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	if(n%2==1)
		flag=0;
	else
	{
		sort(p,p+n,cmp);
		for(int i=1;i<n/2;i++)
			if(p[i].x+p[n-1-i].x!=p[i-1].x+p[n-i].x||p[i].y+p[n-1-i].y!=p[i-1].y+p[n-i].y)
			{flag=0;break;}
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
