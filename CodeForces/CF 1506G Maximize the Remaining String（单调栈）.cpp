#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int t,cnt[30],vis[30];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		string a,ans;
		cin>>a;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		int k=0,len=a.length();
		for(int i=0;i<len;i++)
			cnt[a[i]-'a']++;
		for(int i=0;i<26;i++)
			if(cnt[i]>0)
				k++;
		stack<char> s;
		for(int i=0;i<len;i++)
		{
			cnt[a[i]-'a']--;
			if(vis[a[i]-'a'])
				continue;
			while(!s.empty()&&a[i]>s.top()&&cnt[s.top()-'a']>0)
			{
				vis[s.top()-'a']=0;
				s.pop();
			}
			s.push(a[i]);
			vis[a[i]-'a']=1;
		}
		for(int i=1;i<=k;i++)
		{
			ans+=s.top();
			s.pop();
		}
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
	return 0;
}
