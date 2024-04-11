#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,flag;
struct node
{
	int num,pos,rank;//原数字，原位置，大小排名 
}a[10005],b[10005];
bool cmp(node a,node b)
{
	if(flag==1)
		return a.num>b.num;
	if(flag==2)
		return a.pos<b.pos;
	return false;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].pos=i;
	}
	flag=1;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		a[i].rank=i;
	flag=2;
	sort(a+1,a+n+1,cmp);	
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].num;
		b[i].pos=i;
	}
	flag=1;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
		b[i].rank=i;
	for(int i=n;i>=1;i--)//注意帽子的顺序是反过来的 
	{
		cout<<b[a[i].rank].pos;
		if(i>1) cout<<" ";//注意格式，不能多输出空格 
	}
	return 0;
}
