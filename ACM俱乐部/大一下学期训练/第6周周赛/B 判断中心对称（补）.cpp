#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
	int x,y;
}p[100005];
bool cmp(point a,point b)
{
	if(a.x<b.x)
		return true;
	else if(a.x==b.x)
		return a.y<b.y;
	else
		return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	int flag=1;
	if(n%2)
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
