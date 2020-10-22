#include <iostream>
#include <cstdio>
using namespace std;
int a[300005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int maxn=0,pos=0;
		for(int i=1;i<=n;i++)
			if(a[i]>maxn||a[i]==maxn&&(a[i-1]<a[i]||i<n&&a[i+1]<a[i]))
			{
				maxn=a[i];
				pos=i;
			}
		if(pos==1)
		{
			if(a[pos+1]<a[pos])
				cout<<pos<<endl;
			else
				cout<<"-1"<<endl;
			continue;
		}
		else if(pos==n)
		{
			if(a[pos-1]<a[pos])
				cout<<pos<<endl;
			else
				cout<<"-1"<<endl;
			continue;
		}
		else
		{
			if(a[pos-1]<a[pos]||a[pos+1]<a[pos])
				cout<<pos<<endl;
			else
				cout<<"-1"<<endl;
			continue;
		}
	}
	return 0;
}
