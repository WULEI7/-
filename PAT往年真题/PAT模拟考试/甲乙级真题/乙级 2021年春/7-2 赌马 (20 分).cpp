#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-8;
bool equal(double a,double b)
{
	if(abs(a-b)<eps)
		return true;
	return false;
}
struct node
{
	int num;
	double time;
	bool operator < (const node b) const
	{
		if(equal(time,b.time))
			return num<b.num;
		return time<b.time;
	}
}p[10005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	double a,b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m>>a>>b;
		p[i].num=m;
		p[i].time=a/b;
	}
	sort(p,p+n);
	printf("%d %d %d\n",p[0].num,p[1].num,p[2].num);
	return 0;
}
