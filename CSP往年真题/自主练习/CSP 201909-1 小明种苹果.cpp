#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,m,t=0,k=1,a,b,p[1005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		t+=a;
		for(int j=1;j<=m;j++)
		{
			cin>>b;
			t+=b;
			p[i]-=b;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(p[i]>p[1])
		{
			p[1]=p[i];
			k=i;
		}
	}
	cout<<t<<" "<<k<<" "<<p[1]<<endl;
	return 0;
}
