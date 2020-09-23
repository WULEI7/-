#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,t,ans=0,tap[105]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		int minn=99999999,pos=0;
		for(int j=0;j<m;j++)
			if(tap[j]<minn)
			{
				minn=tap[j];
				pos=j;
			}
		tap[pos]+=t;
	}
	for(int i=0;i<m;i++)
		if(tap[i]>ans)
			ans=tap[i];
	cout<<ans<<endl;
	return 0;
}
