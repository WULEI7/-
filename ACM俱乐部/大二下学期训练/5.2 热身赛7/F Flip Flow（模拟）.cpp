#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,s,n,l,a[1005];
	cin>>t>>s>>n;
	l=s;
	for(int i=0;i<n;i++)
		cin>>a[i];
	a[n]=t;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			if(a[i]-a[i-1]<l)
				l-=a[i]-a[i-1];
			else
				l=0;
		}
		else
		{
			if(a[i]-a[i-1]<s-l)
				l+=a[i]-a[i-1];
			else
				l=s;
		}
	}
	if(n%2==1)
		cout<<l<<endl;
	else
		cout<<s-l<<endl;
	return 0;
}
