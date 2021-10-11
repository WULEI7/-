#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,m;
long long r,p[100005],q[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		r=0;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
			r+=p[i];
			p[i]+=p[i-1];
		}
		for(int i=1;i<=m;i++)
			cin>>q[i];
		for(int i=1;i<=m;i++)
		{
			if(q[i]==0)
			{
				cout<<"0"<<endl;
				continue;
			}
			int flag=0;
			long long minn=1999999999;
			for(int j=1;j<=n;j++)
			{
				if(((q[i]-p[j]>=0&&r>=0||q[i]-p[j]<0&&r<0))&&(q[i]-p[j])%r==0)
				{
					flag=1;
					minn=min(minn,j+n*(q[i]-p[j])/r);
				}
			}
			if(flag==0)
				cout<<"-1"<<endl;
			else
				cout<<minn<<endl;
		}
	}
	return 0;
}
