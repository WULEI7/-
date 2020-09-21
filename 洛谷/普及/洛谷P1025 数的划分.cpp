#include <iostream>
#include <cstdio>
using namespace std;
int ans=0;
void dfs(int cnt,int fen,int num)
{
	if(fen==1)
	{
		ans++;
		return;
	}
	for(int i=cnt;i<=num/fen;i++)
		dfs(i,fen-1,num-i);
}
int main()
{
	int n,k;
	cin>>n>>k;
	dfs(1,k,n);
	cout<<ans<<endl;
	return 0;
}
