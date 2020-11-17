#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int a=abs(x1-x2),b=abs(y1-y2);
		int ans=a+b;
		if(a>0&&b>0)
			ans+=2;
		cout<<ans<<endl; 
	}
	return 0;
}
