#include <iostream>
#include <cstdio>
using namespace std;
int d[100005],r[100005],g[100005],T[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++)
		cin>>d[i];
	for(int i=0;i<n;i++)
		cin>>r[i];
	for(int i=0;i<n;i++)
	{
		cin>>g[i];
		T[i]=r[i]+g[i];//ÖÜÆÚ 
	}
	for(int i=0;i<n;i++)
	{
		if(i>0)
			m+=d[i];
		if(m%T[i]>g[i])
			m+=T[i]-m%T[i];
		cout<<m<<endl;
	}
	return 0;
}
