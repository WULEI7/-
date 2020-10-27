#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int minn=1999999999,flag=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			if(a<minn)
				minn=a;
			else
				flag=1;
		}
		if(flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
