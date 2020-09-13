#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int yu,shu,ying,tot,num;
}stu[305];
bool cmp(node a,node b)
{
	if(a.tot!=b.tot)
		return a.tot>b.tot;
	else if(a.yu!=b.yu)
		return a.yu>b.yu;
	else
		return a.num<b.num;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>stu[i].yu>>stu[i].shu>>stu[i].ying;
		stu[i].tot=stu[i].yu+stu[i].shu+stu[i].ying;
		stu[i].num=i;
	}
	sort(stu+1,stu+n+1,cmp);
	for(int i=1;i<=5;i++)
		printf("%d %d\n",stu[i].num,stu[i].tot);
	return 0;
}
