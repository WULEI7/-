#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,x,a[55],b[55];
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		reverse(b,b+n);
		int flag=1;
		for(int i=0;i<n;i++)
			if(a[i]+b[i]>x)
			{
				flag=0;
				break;
			}
		if(flag==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
