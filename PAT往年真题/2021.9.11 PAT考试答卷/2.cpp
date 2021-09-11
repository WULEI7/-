#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int num,pos,rank;
}p[10005];
int flag=1;
bool cmp(node a,node b)
{
	if(flag==1)
		return a.num>b.num;
	if(flag==2)
		return a.pos>b.pos;
}
struct Node
{
	int num,pos;
	bool operator < (const Node b) const
	{
		return num>b.num;
	}
}q[10005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].num;
		p[i].pos=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].num;
		q[i].pos=i;
	}
	sort(p+1,p+n+1,cmp);
	sort(q+1,q+n+1);
	for(int i=1;i<=n;i++)
		p[i].rank=i;
	flag=2;
	sort(p+1,p+n+1,cmp);
	//for(int i=1;i<=n;i++)
	//	cout<<p[i].num<<" "<<p[i].pos<<" "<<p[i].rank<<endl;
	cout<<q[p[1].rank].pos;
	for(int i=2;i<=n;i++)
		cout<<" "<<q[p[i].rank].pos;
	return 0;
}
