#include <iostream>
using namespace std;
int Euler[1000005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	Euler[1]=0;//特殊 
	for(int i=2;i<1000005;i++)
		Euler[i]=i;
	for(int i=2;i<1000005;i++)
		if(Euler[i]==i)
			for(int j=i;j<1000005;j+=i)
				Euler[j]=Euler[j]/i*(i-1);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int n;
		cin>>n;
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			for(int j=a+1;j<1000005;j++)//注意从a+1开始找，不然会超时 
				if(Euler[j]>=a)
				{
					ans+=j;
					break;
				}
		}
		cout<<"Case "<<k<<": "<<ans<<" Xukha"<<endl;
	}
	return 0;
}
