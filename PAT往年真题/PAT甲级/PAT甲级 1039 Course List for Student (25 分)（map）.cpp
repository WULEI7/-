#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<int> v[40005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,m,no,num=0;
	string s;
	map<string,int> mp;
	cin>>n>>k;
	while(k--)
	{
		cin>>no>>m;
		while(m--)
		{
			cin>>s;
			if(mp.count(s)==0)
				mp[s]=num++;
			v[mp[s]].push_back(no);
		}
	}
	while(n--)
	{
		cin>>s;
		cout<<s<<" ";
		if(mp.count(s)==0)
		{
			cout<<"0"<<endl;
			continue;
		}
		num=mp[s];
		int size=v[num].size();
		cout<<size;
		sort(v[num].begin(),v[num].end());
		for(int i=0;i<size;i++)
			cout<<" "<<v[num][i];
		cout<<endl;
	}
	return 0; 
}
