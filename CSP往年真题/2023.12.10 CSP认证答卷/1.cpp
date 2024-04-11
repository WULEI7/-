#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
struct node
{
	int id;
	int t[11];
}p[1005],q[1005];
/*
bool cmp(node a,node b)
{
	for(int i=1;i<=m;i++)
	{
		if(a.t[i]<b.t[i])
			return true;
		if(a.t[i]>b.t[i])
			return false;
	}
	return false;
}
*/
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		p[i].id=i;
		for(int j=1;j<=m;j++)
		{
			cin>>p[i].t[j];
			//q[i].t[j]=p[i].t[j];
		}
	}
	//sort(p+1,p+n+1,cmp);
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<p[i].id<<" : ";
		for(int j=1;j<=m;j++)
			cout<<p[i].t[j]<<" ";
		cout<<endl;
	}
	*/
	/*
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(p[j].t[k]<=q[i].t[k])
					break;
				if(k==m)
				{
					flag=0;
					cout<<p[j].id<<endl;
				}
			}
			if(flag==0) break;
		}
		if(flag)
			cout<<"0"<<endl;		
	}
	*/
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(p[j].t[k]<=p[i].t[k])
					break;
				if(k==m)
				{
					flag=0;
					cout<<p[j].id<<endl;
				}
			}
			if(flag==0) break;
		}
		if(flag)
			cout<<"0"<<endl;		
	}
	return 0;
}