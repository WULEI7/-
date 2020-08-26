#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	int e,w;
}way[1000005];//�洢��·�Ķ������� 
struct Node
{
	int left,right,value;
}tree[1005*4];//�洢���˸��㹫·�������߶��� 
bool cmp(node a,node b)
{
	if(a.e<b.e) return 1;
	else if(a.e==b.e) return a.w<b.w;
	else return 0;
}//�����Թ�·�������� 
void build(int o,int l,int r)
{
	tree[o].left=l;
	tree[o].right=r;
	tree[o].value=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
}//���� 
void update(int o,int pos)
{
	if(tree[o].left==tree[o].right)
	{
		tree[o].value++;//��·��������1 
		return;
	}
	int mid=(tree[o].left+tree[o].right)/2;
	if(pos<=mid)
		update(o*2,pos);
    else
		update(o*2+1,pos);
	tree[o].value=tree[o*2].value+tree[o*2+1].value;
}//���� 
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
}//��ѯ 
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
		sort(way,way+k,cmp);//�Թ�·�������� 
		build(1,1,m);
		for(int i=0;i<k;i++)
		{
			update(1,way[i].w);
			if(way[i].w<m)
				ans+=query(1,way[i].w+1,m);//�����뵱ǰ��·����Ĺ�·���� 
		}
		printf("Test case %d: %lld\n",t,ans);
	}
	return 0;
}
