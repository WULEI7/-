#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	string s,t;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		t+='0';
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<=n-m;j++)
		{
			int flag=1;
			for(int k=0;k<m;k++)
				if(s[j+k]!=t[k])
				{
					flag=0;
					break;
				}
			if(flag==1)
				ans++;
		}
	}
	cin>>s;
	cout<<ans<<endl;
	return 0;
}
