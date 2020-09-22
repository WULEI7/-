#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,v[35],ans[20005]={0};
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>v[i];
	for(int i=0;i<m;i++)
		for(int j=n;j>=v[i];j--)
			if(ans[j]<ans[j-v[i]]+v[i])
				ans[j]=ans[j-v[i]]+v[i];
	cout<<n-ans[n]<<endl;
	return 0;
}
