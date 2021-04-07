#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int inf=1999999999;
int n,ans=inf;
map<vector<int>,int> mp;
void dfs(vector<int> a,int time)
{
	int flag=1;
	for(int i=0;i<2*n;i++)
	{
		if(a[i]!=i+1)
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		if(time<ans)
			ans=time;
	}
	vector<int> t1;
	for(int i=0;i<2*n;i+=2)
	{
		t1.push_back(a[i+1]);
		t1.push_back(a[i]);
	}
	if(!mp.count(t1)) 
	{
		mp[t1]=1;
		dfs(t1,time+1);
		mp.erase(t1);
	}
	vector<int> t2;
	for(int i=n;i<2*n;i++)
		t2.push_back(a[i]);
	for(int i=0;i<n;i++)
		t2.push_back(a[i]);
	if(!mp.count(t2))
	{
		mp[t2]=1;
		dfs(t2,time+1);
		mp.erase(t2);
	}
}
int main()
{
	cin>>n;
	vector<int> a(2*n);
	for(int i=0;i<2*n;i++)
		cin>>a[i];
	mp[a]=1;
	dfs(a,0);
	if(ans==inf)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
