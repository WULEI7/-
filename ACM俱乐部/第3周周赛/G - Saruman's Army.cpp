#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int r,n;
	while(cin>>r>>n)
	{
		if(r==-1&&n==-1) break;
		int x[1005],ans=0;
		for(int i=0;i<n;i++)
			cin>>x[i];
		sort(x,x+n);
		for(int i=0;i<n;)
		{
			int temp=x[i++];
		//	while(x[i]<=temp1+r&&i<n)
			for(;i<n;i++)
				if(x[i]>temp+r)
					break;
			temp=x[i-1];
		//	while(x[i]<=temp2+r&&i<n)
			for(;i<n;i++)
				if(x[i]>temp+r)
					break;
			ans++;//temp记录当前放置的圆心 
		}
		cout<<ans<<endl;
	}
	return 0;
}
