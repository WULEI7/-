#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,m,a[100005];
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int temp=0,mpos=0,maxn=0;
		for(int i=0;i<n;i++)
		{
			temp+=a[i];
			if(a[i]>maxn)
			{
				mpos=i+1;
				maxn=a[i];
			}
			if(temp>m)
				break;
			if(i==n-1)
				mpos=0;
		}
		cout<<mpos<<endl;
	}
	return 0;
}
