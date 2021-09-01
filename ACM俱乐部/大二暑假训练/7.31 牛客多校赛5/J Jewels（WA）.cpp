#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int x,y,z,v;
}p[305];
bool cmp(node a,node b)
{
	return a.v>b.v;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y>>p[i].z>>p[i].v;
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++)
	{
		ans+=p[i].x*p[i].x+p[i].y*p[i].y+p[i].z*p[i].z;
		for(int j=i+1;j<n;j++)
			p[j].z+=p[j].v;
		sort(p,p+n,cmp);
	}
	cout<<ans<<endl;
	return 0;
}
