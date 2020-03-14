#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int a[10001],b[10001];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		set<int> ans;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			ans.insert(a[i]);
		}
		for(int i=0;i<m;i++)
		{
			cin>>b[i];
			ans.insert(b[i]);
		}
		set<int>::iterator it=ans.begin();
		cout<<*it;
		it++;
		for(;it!=ans.end();it++)
		{
			cout<<" "<<*it;
		}
		cout<<endl;
	}
	return 0;
}
