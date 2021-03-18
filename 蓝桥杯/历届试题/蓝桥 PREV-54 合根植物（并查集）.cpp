#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int fa[1000005];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n,k;
	cin>>m>>n>>k;
	int size=m*n;
	for(int i=1;i<=size;i++)
		fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		int x=find(a),y=find(b);
		if(x!=y)
			fa[x]=y;
	}
	int ans=0;
	for(int i=1;i<=size;i++)
		if(i==find(i))
			ans++;
	/*
	for(int i=1;i<=size;i++)
		find(i);
	sort(fa+1,fa+size+1);
	int ans=1;
	for(int i=2;i<=size;i++)
		if(fa[i]!=fa[i-1])
			ans++;
	*/
	cout<<ans<<endl;
	return 0;
}
