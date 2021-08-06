#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int x,y;
}cnt[1005];
bool cmp(node a,node b)
{
	return a.y==b.y?(a.x<b.x):(a.y>b.y);
}
int main()
{
	for(int i=0;i<=1000;i++)
	{
		cnt[i].x=i;
		cnt[i].y=0;
	}
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		cnt[m].y++;
	}
	sort(cnt,cnt+1001,cmp);//注意此处必须是1001 
	for(int i=0;i<=1000;i++)
	{
		if(cnt[i].y==0) break;
		printf("%d %d\n",cnt[i].x,cnt[i].y);
	}
	return 0;
}
