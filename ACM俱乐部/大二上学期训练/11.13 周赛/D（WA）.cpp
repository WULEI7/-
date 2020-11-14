#include <iostream>
#include <cstdio>
using namespace std;
long long a[300005][2];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i][0]>>a[i][1];
	}
	long long minn=1e14,pos;
	for(int i=0;i<n;i++)
		if(a[i][0]<minn)
		{
			minn=a[i][0];
			pos=i;
		}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=a[(pos+i)%n][0];
		long long temp=a[(pos+i)%n][0];
		while(temp)
		{
			
			if(a[(pos+i)%n][1]-temp>0)
				a[(pos+i)%n][1]-=temp;
			else
			{
				temp-=a[(pos+i)%n][1];
				i++;
				n--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
