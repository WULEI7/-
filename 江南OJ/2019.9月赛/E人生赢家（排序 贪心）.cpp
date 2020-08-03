#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
	int l,r;
}work[100005];
bool cmp(node a,node b)
{
	return a.l==b.l?(a.r<b.r):(a.l<b.l);
}
int main()
{
	int n,m,ans;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d",&work[i].l,&work[i].r);
	sort(work,work+m,cmp);
	int left=work[0].l-1,right=n-work[0].r;
	ans=max(left,right);
	int you=work[0].r;//当前的最右端点 
	for(int i=1;i<m;i++)
	{
		if(work[i].l<=you&&work[i].r>you)
		{
			ans=max(left,n-work[i].r);
			you=work[i].r;
		}
		else if(work[i].l>you)
		{
			int temp=max(work[i].l-work[i-1].r-1,n-work[i].r);
			ans=max(left,temp);
			you=work[i].r;
		}
	}
	printf("%d\n",ans);
	return 0;
}
