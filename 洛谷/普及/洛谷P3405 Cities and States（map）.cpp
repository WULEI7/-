#include <iostream>
#include <cstdio>
#include <map> 
using namespace std;
map<string,int> cnt;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;
	string x,y;
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		x=x.substr(0,2);
		if(x==y) continue;
		ans+=cnt[y+x];
		cnt[x+y]++;
	}
	cout<<ans<<endl;
	return 0;
}
