#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,t,box,ans;
	cin>>n>>t;
	if(n%t==0) box=n/t;
	else box=n/t+1;
	ans=n/box;
	cout<<ans<<endl;
	return 0;
}
