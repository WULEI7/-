#include <iostream>
#include <cstdio>
using namespace std;
int n,m,q,start,length,tl=0,tr=0,ans=1;
int flag[10005];
struct node
{
	int add,num;
}p[1300000];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int k=1;k<=n;k++)
	{
		cin>>start>>length;
		tl=tr;
		tr+=length;
		for(int i=tl;i<tr;i++)
		{
			p[i].add=start+4*(i-tl);
			p[i].num=k;
		}
	}
	while(m--)
	{
		cin>>q;
		if(q>=tr)
		{
			cout<<"Illegal Access"<<endl;
			continue;
		}
		cout<<p[q].add<<endl;
		flag[p[q].num]=1;
	}
	for(int i=10000;i>=1;i--)
		if(flag[i])
		{
			ans=i;
			break;
		}
	cout<<ans<<endl;
	return 0;
}
