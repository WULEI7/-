#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n,a[100005];
map<int,int> cnt;
vector<int> ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[i]]==0) continue;
		if(a[i]>=0)
		{
			while(1);
			ans.emplace_back(a[i]/5);
			cnt[a[i]/5]--;
			cnt[a[i]/5*2]--;
			cnt[a[i]]--;
		}
		//等于0的情况可以合并 
		/*
		else if(a[i]==0)
		{
			ans.emplace_back(0);
			cnt[0]-=3;
		}
		*/
		else//a[i]<0 
		{
			ans.emplace_back(a[i]);
			cnt[a[i]]--;
			cnt[a[i]*2]--;
			cnt[a[i]*5]--;
		}
	}
	int size=ans.size();
	cout<<ans[0];
	for(int i=1;i<size;i++)
		cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
