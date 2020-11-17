#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int cnt,minn=1999999999;
		for(int i=1;i<=n;i++)
		{
			cnt=i-1;
			if(n%i==0)
				cnt+=n/i-1;
			else
				cnt+=n/i;
			if(cnt<=minn)//此处必须包含等于 
				minn=cnt;
			else
				break;
		}
		cout<<minn<<endl;
	}
	return 0;
}
