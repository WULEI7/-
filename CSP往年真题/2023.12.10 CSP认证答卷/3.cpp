#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,t;
int w[2005],p[2005],q[2005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int flag20=1;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		q[1]+=w[i];
	}
	for(int i=2;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]!=1) flag20=0;
	}
	//cout<<q[1]<<endl;
	if(flag20)//20%
	{
		while(m--)
		{
			cin>>t;
			if(t==1)
			{
				for(int i=2;i<=n;i++)
					cout<<i<<" ";
			}
			else
			{
				for(int i=2;i<=t;i++)
					cout<<i<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}