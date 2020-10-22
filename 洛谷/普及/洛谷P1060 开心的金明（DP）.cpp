#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,val,v[30],p[30],ans[30005];
	cin>>val>>n;
	for(int i=0;i<n;i++)
	{
		cin>>v[i]>>p[i];
		p[i]*=v[i];
	}
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;i++)
	for(int j=val;j>=0;j--)
		if(j>=v[i])
		if(ans[j]<ans[j-v[i]]+p[i])
			ans[j]=ans[j-v[i]]+p[i];
	cout<<ans[val]<<endl;
	return 0;
}
