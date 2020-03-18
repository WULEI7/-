#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int p[1005];
int fun(int n)
{
	if(n==1)
		return p[1];
	else if(n==2)
		return p[2];
	else if(n==3)
		return p[1]+p[2]+p[3];
	else
		return min((p[1]*2+p[n-1]+p[n]+fun(n-2)),(p[1]+p[2]*2+p[n]+fun(n-2)));
}
int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>p[i];
		sort(p+1,p+n+1);
		cout<<fun(n)<<endl;
	}
	return 0;
}
