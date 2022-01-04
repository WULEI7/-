#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,w,t,ans=0,cnt=0,tweight=0,tcnt=0;
	cin>>n>>w;
	while(n--)
	{
		cin>>t;
		tweight+=t;
		tcnt++;
		if(tweight==w)
		{
			ans++;
			cnt+=tcnt;
			tweight=0;
			tcnt=0;
		}
		if(tweight>w)
		{
			tweight-=t;
			tcnt--;
		}
	}
	cout<<ans<<" "<<cnt<<endl;
	return 0;
}
