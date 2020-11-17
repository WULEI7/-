#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,m,a,b,c,d;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b>>c>>d;
			if(b==c) flag=1;
		}
		if(m%2==0&&flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
