#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int cnt0[100005],cnt1[100005];
pair<int,int> stu[100005];
set<int> check;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,ans,maxcnt=0;
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>stu[i].first>>stu[i].second;
	sort(stu+1,stu+m+1);
	for(int i=1;i<=m;i++)
	{
		cnt1[i]=cnt1[i-1]+stu[i].second;
		cnt0[i]=i-cnt1[i];
	}//前缀和，记录到第i个位置当中0和1的数量 
	for(int i=1;i<=m;i++)
	{
		int num=stu[i].first;
		if(check.count(num)) continue;
		check.insert(num);
		int temp=cnt0[i-1]+cnt1[m]-cnt1[i-1];
		if(temp>=maxcnt)
		{
			maxcnt=temp;
			ans=stu[i].first;
		}
	}
	cout<<ans<<endl;
	return 0;
}
