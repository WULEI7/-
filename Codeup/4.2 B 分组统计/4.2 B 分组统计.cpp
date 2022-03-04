#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a[105],b[105];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		set<int> num;
		map<int,int> cnt[105];
		for(int i=0;i<n;i++)
		{
			num.insert(a[i]);
			cnt[b[i]][a[i]]++;
		}
		for(int i=1;i<=100;i++)
		{
			if(cnt[i].size()>0)
			{
				cout<<i<<"={";
				for(set<int>::iterator it=num.begin();it!=num.end();it++)
				{
					if(it!=num.begin())
						cout<<",";
					cout<<*it<<"="<<cnt[i][*it];
				}
				cout<<"}"<<endl;
			}
		}
	}
	return 0; 
}
