#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a,b,g[13][13];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=12;i++)
	{
		cin>>t;
		cin>>n;
		while(n--)
		{
			cin>>a;
			g[t][a]=g[a][t]=1;
		}
		cin>>n;
		while(n--)
		{
			cin>>a;
			g[t][a]=g[a][t]=-1;
		}
	}
	/*
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=12;j++)
			cout<<g[i][j]<<"\t";
		cout<<endl;
	}
	*/
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(g[a][b]==1)
			cout<<"Yes"<<endl;
		else if(g[a][b]==-1)
			cout<<"No"<<endl;
		else
			cout<<"NA"<<endl;
	}
	return 0;
}
