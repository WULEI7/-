#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int d,s;
};
bool cmp(node x,node y)
{
	if(x.s==y.s)
		return x.d<y.d;
	else
		return x.s>y.s;
}

int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--)
	{
		int day[1005]={0};
		node h[1005];
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>h[i].d;
		for(int i=0;i<n;i++)
			cin>>h[i].s;
		sort(h,h+n,cmp);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int j;
			for(j=h[i].d;j>0;j--)
			{
				if(day[j]==0)
				{
					day[j]=1;
					break;
				}
			}
			if(j==0)
				ans+=h[i].s;
		}
		cout<<ans<<endl;
	}
	return 0;
}
