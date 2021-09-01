#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,k,a[30][30],ans=0;
void dfs(int temp,int len)
{
	ans=max(ans,len);
	for(int i=0;i<26;i++)
		if(a[temp][i]==n)
			dfs(i,len+1);
}
void bfs(int temp,int len)
{
	queue<pair<int,int>> q;
	q.push({temp,len});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		ans=max(ans,p.second);
		for(int i=0;i<26;i++)
			if(a[p.first][i]==n)
				q.push({i,p.second+1});
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int i=0;i<k;i++)
		for(int j=i+1;j<k;j++)
			a[s[i]-'A'][s[j]-'A']++;//预处理字母前后位置关系 
	}
	for(int i=0;i<26;i++)
		//dfs(i,1);
		bfs(i,1);
	cout<<ans<<endl;
	return 0;
}
