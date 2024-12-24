#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,x0,y0;
struct node
{
	int x,y,num;
}dian[205];
bool cmp(node a,node b)
{
	return (a.x-x0)*(a.x-x0)+(a.y-y0)*(a.y-y0)!=(b.x-x0)*(b.x-x0)+(b.y-y0)*(b.y-y0) ? (a.x-x0)*(a.x-x0)+(a.y-y0)*(a.y-y0)<(b.x-x0)*(b.x-x0)+(b.y-y0)*(b.y-y0) : a.num<b.num;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>x0>>y0;
	for(int i=1;i<=n;i++)
	{
		cin>>dian[i].x>>dian[i].y;
		dian[i].num=i;
	}
	sort(dian+1,dian+n+1,cmp);
	for(int i=1;i<=3;i++)
		cout<<dian[i].num<<endl;
	return 0;
}