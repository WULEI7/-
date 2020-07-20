#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct node
{
	int left,right,value;//value的值：1铜、2银、3金 
}tree[100005*4];
void build(int o,int l,int r)
{
	tree[o].left=l;
	tree[o].right=r;
	tree[o].value=1;
	if(l==r)
		return;
	int mid=(tree[o].left+tree[o].right)/2;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
}//建树 
int query(int o,int l,int r)
{
	if(tree[o].value!=0)
		return (tree[o].right-tree[o].left+1)*tree[o].value;
	else
		return query(o*2,l,r)+query(o*2+1,l,r);
}//查询 
void update(int o,int l,int r,int x)
{
	if(tree[o].value==x)
		return;
	if(tree[o].left==l&&tree[o].right==r)
	{
		tree[o].value=x;
		return;
	}
	if(tree[o].value!=0)
	{
		tree[o*2].value=tree[o*2+1].value=tree[o].value;
		tree[o].value=0;
	}
	int mid=(tree[o].left+tree[o].right)/2;
	if(r<=mid)
		update(o*2,l,r,x);
	else if(l>mid)
		update(o*2+1,l,r,x);
	else
	{
		update(o*2,l,mid,x);
		update(o*2+1,mid+1,r,x);
	}
}//修改 
int main()
{
	int t,n,m;
	scanf("%d",&t);
	for(int T=1;T<=t;T++)
	{
		scanf("%d",&n);
		build(1,1,n);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			update(1,x,y,z);
		}
		printf("Case %d: The total value of the hook is %d.\n",T,query(1,1,n));
	}
	return 0;
}
