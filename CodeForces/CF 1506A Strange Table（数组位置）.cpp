#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long t,r,c,pos,row,col,ans;
	cin>>t;
	while(t--)
	{
		cin>>r>>c>>pos;
		if(pos%r==0)
		{
			col=pos/r;
			row=r;
		}
		else
		{
			col=pos/r+1;
			row=pos%r;
		}
		ans=(row-1)*c+col;
		cout<<ans<<endl;
	}
	return 0;
}
