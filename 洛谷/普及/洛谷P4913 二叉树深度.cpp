#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;
struct node
{
	int l,r;
}a[1000005];
int maxn=0;
void dfs(int root,int temp)
{
	if(root==0) return;
	maxn=max(maxn,temp);
	dfs(a[root].l,temp+1);
	dfs(a[root].r,temp+1);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
		cin>>a[i].l>>a[i].r;
	dfs(1,1);
	cout<<maxn<<endl;
	return 0;
}
