#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,k,a[105];
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int left=0,right=n-1;
		while(k--)
		{
			while(a[left]==0) left++;
			if(left>=right) break;
			a[left]--;
			a[right]++;
		}
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
