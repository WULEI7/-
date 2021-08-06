#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=n;i<=m;i++)
	{
		if(i==1) continue;
		int cnt=1;
		for(int j=1;j<=i/2;j++)
			if(i%j==0)
				cnt++;
		if(cnt>ans)
			ans=cnt;
	}	
	cout<<ans<<endl;
	return 0;
}
