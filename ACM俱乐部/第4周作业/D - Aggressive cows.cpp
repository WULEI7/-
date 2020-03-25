#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,k,x[100005];
bool check(int d)
{
	int last=0;
	for(int i=1;i<k;i++)
	{
		int cur=last+1;
		while(cur<n&&x[cur]-x[last]<d)
			cur++;
		if(cur==n)
			return false;
		last=cur;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>x[i];
	sort(x,x+n);
	int l=0,r=x[n-1];
	while(r-l>1)
	{
		int mid=(r+l)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}

