#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	int e,w;
}way[1000005];//存储公路的东西两端 
struct Node
{
	int left,right,value;
}tree[1005*4];//存储西端各点公路数量的线段树 
bool cmp(node a,node b)
{
	if(a.e<b.e) return 1;
	else if(a.e==b.e) return a.w<b.w;
	else return 0;
}//用来对公路进行排序 
void build(int o,int l,int r)
{
	tree[o].left=l;
	tree[o].right=r;
	tree[o].value=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
}//建树 
void update(int o,int pos)
{
	if(tree[o].left==tree[o].right)
	{
		tree[o].value++;//公路的数量加1 
		return;
	}
	int mid=(tree[o].left+tree[o].right)/2;
	if(pos<=mid)
		update(o*2,pos);
    else
		update(o*2+1,pos);
	tree[o].value=tree[o*2].value+tree[o*2+1].value;
}//更新 
int query(int o,int l,int r)
{
	if(l<=tree[o].left&&tree[o].right<=r)
		return tree[o].value;
	int ans=0,mid=(tree[o].left+tree[o].right)/2;
	if(l<=mid)
		ans+=query(o*2,l,r);
	if(r>mid)
		ans+=query(o*2+1,l,r);
	return ans;
}//查询 
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int n,m,k;
		long long ans=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;i++)
			scanf("%d%d",&way[i].e,&way[i].w);
		sort(way,way+k,cmp);//对公路进行排序 
		build(1,1,m);
		for(int i=0;i<k;i++)
		{
			update(1,way[i].w);
			if(way[i].w<m)
				ans+=query(1,way[i].w+1,m);//加上与当前公路交叉的公路数量 
		}
		printf("Test case %d: %lld\n",t,ans);
	}
	return 0;
}
