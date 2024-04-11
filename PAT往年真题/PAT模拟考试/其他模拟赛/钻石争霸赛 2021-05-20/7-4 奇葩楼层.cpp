#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		int temp=i,flag=1;
		while(temp)
		{
			if(temp%10==d)
			{
				flag=0;
				break;
			}
			temp/=10;
		}
		if(flag) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
