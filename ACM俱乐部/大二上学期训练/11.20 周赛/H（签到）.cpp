#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int c1=0,c2=0,c3=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]<0) c1++;
			if(a[i]==0) c2++;
			if(a[i]>0) c3++;
		}
		sort(a,a+n);
		if(c1+c3<5)
			cout<<"0"<<endl;
		else
		{
			if(c1==0||c1==1)
				cout<<a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5]<<endl;
			if(c1==2||c1==3)
			{
				if(a[0]*a[1]>a[n-4]*a[n-5])
					cout<<a[n-1]*a[n-2]*a[n-3]*a[0]*a[1]<<endl;
				else
					cout<<a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5]<<endl;
			}
			if(c1>=4&&c2+c3>0)
			{
				long long ans=a[n-1];
				if(a[0]*a[1]>a[n-4]*a[n-5])
					ans*=a[0]*a[1];
				else
					ans*=a[n-4]*a[n-5];
				if(a[2]*a[3]>a[n-2]*a[n-3])
					ans*=a[2]*a[3];
				else
					ans*=a[n-2]*a[n-3];
				cout<<ans<<endl;
			}
			if(c1>=5&&c2+c3==0)
				cout<<a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5]<<endl;
		}
	}
	return 0;
}
