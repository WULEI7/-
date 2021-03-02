#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[50005],ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int maxn=a[i],minn=a[i];
		for(int j=i;j<n;j++)
		{
			if(a[j]>maxn) maxn=a[j];
			if(a[j]<minn) minn=a[j];
			if(maxn-minn==j-i) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
