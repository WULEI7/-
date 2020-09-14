#include <iostream>
#include <cstdio>
#include <algorithm>
struct node
{
	int num,pot;
}per[5005];
bool cmp(node a,node b)
{
	return a.pot!=b.pot ? a.pot>b.pot:a.num<b.num;
}
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m;
	k=m*3/2;
	for(int i=0;i<n;i++)
		cin>>per[i].num>>per[i].pot;
	sort(per,per+n,cmp);
	for(int i=k;;i++)
	{
		if(per[i].pot==per[i-1].pot)
			k++;
		else break;
	}
	printf("%d %d\n",per[k-1].pot,k);
	for(int i=0;i<k;i++)
		printf("%d %d\n",per[i].num,per[i].pot);
	return 0;
}
