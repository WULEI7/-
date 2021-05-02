#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	string s;
	int l;
}p[105];
bool cmp(node a,node b)
{
	if(a.l!=b.l)
		return a.l<b.l;
	else
	{
		if(a.s=="cylinder")
			return true;
		return false;
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].s>>p[i].l;
		if(p[i].s=="cylinder")
			p[i].l*=2;
	}
	sort(p,p+n,cmp);
	int flag=1;
	for(int i=1;i<n;i++)
	{
		if(p[i].s=="cylinder")
			if(p[i].l/sqrt(2)<p[i-1].l)
			{
				flag=0;
				break;
			}
	}
	if(flag==0)
		cout<<"impossible"<<endl;
	else
	{
		for(int i=0;i<n;i++)
		{
			if(p[i].s=="cylinder")
				cout<<"cylinder "<<p[i].l/2<<endl;
			else
				cout<<"cube "<<p[i].l<<endl;
		}
	}
	return 0;
}
