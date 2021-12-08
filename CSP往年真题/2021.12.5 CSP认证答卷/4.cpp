#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,k,a,id,l,r,x;
struct node
{
	int id=0;
	int num;
}p[1000005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a;
		if(a==0)
		{
			cin>>id>>l>>r>>x;
			for(int i=l;i<=r;i++)
			{
				p[i].id=id;
				p[i].num=x;
			}
			cout<<r<<endl;
		}
		if(a==1)
		{
			
		}
		if(a==2)
		{
			
		}
		if(a==3)
		{
			cin>>x;
			if(p[x].id==0)
				cout<<"0 0"<<endl;
			else
				cout<<p[x].id<<" "<<p[x].num<<endl;
		}
	}
	return 0;
}