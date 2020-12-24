#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n,ans;
	cin>>n;
	ans=n+1;
	for(j=2;j<n;j++)
		ans+=(1+j)*j/2;
	cout<<ans;
	return 0;
}
