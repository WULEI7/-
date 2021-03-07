#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int n,k,a[200005],cnt[200005],vis[200005],ans[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		cnt[a[i]]--;
		if(vis[a[i]])
			continue;
		while(!s.empty()&&a[i]<s.top()&&cnt[s.top()]>0)
		{
			vis[s.top()]=0;
			s.pop();
		}
		s.push(a[i]);
		vis[a[i]]=1;
	}
	for(int i=k;i>=1;i--)
	{
		ans[i]=s.top();
		s.pop();
	}
	for(int i=1;i<=k;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
