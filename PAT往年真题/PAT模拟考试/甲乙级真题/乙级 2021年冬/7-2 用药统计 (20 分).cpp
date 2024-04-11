#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	map<string,int> cnt;//统计各药品数量 
	map<string,vector<string> > ans;//记录各药品治疗过的疾病编号 
	int t,n;
	string id,md;
	cin>>t;
	while(t--)
	{
		cin>>id>>n;
		for(int i=0;i<n;i++)
		{
			cin>>md;
			cnt[md]++;
			ans[md].emplace_back(id);
		}
	}
	map<string,int>::iterator it;//迭代器 
	int maxcnt=0;
	string maxmd;
	for(it=cnt.begin();it!=cnt.end();it++)
	{
		if(it->second>maxcnt)
		{
			maxmd=it->first;
			maxcnt=it->second;
		}
	}
	cout<<maxmd<<" "<<cnt[maxmd]<<endl;
	int size=ans[maxmd].size();
	for(int i=0;i<size;i++)
		cout<<ans[maxmd][i]<<endl;
	return 0;
}
