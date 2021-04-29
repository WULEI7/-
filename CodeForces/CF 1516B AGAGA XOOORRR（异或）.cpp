#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a[2005];
	cin>>t;
	while(t--)
	{
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum^=a[i];
		}
		if(sum==0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		else
		{
			int temp=0,cnt=0;
			for(int i=0;i<n;i++)
			{
				temp^=a[i];
				if(temp==sum)
				{
					temp=0;
					cnt++;
				}
			}
			if(cnt==1)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
	}
	return 0;
}
