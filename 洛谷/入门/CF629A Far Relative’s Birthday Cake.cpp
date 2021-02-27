#include <iostream>
#include <cstdio>
using namespace std;
char c[101][101];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cin>>c[i][j];
	for(int i=0;i<n;i++)
	{
		int t=0;
		for(int j=0;j<n;j++)
			if(c[i][j]=='C')
				t++;
		ans+=t*(t-1)/2;
	}
	for(int j=0;j<n;j++)
	{
		int t=0;
		for(int i=0;i<n;i++)
			if(c[i][j]=='C')
				t++;
		ans+=t*(t-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}
