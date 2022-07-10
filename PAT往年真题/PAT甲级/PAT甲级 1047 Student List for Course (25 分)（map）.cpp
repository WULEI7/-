#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v[2505];
int main()
{
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,c,t;
	string s;
	cin>>n>>k;
	while(n--)
	{
		cin>>s;
		cin>>c;
		while(c--)
		{
			cin>>t;
			v[t].push_back(s);
		}
	}
	for(int i=1;i<=k;i++)
	{
		sort(v[i].begin(),v[i].end());
		int size=v[i].size();
		cout<<i<<" "<<size<<endl;
		for(int j=0;j<size;j++)
			//cout<<v[i][j]<<endl;
			printf("%s\n",v[i][j].c_str());
	}
	return 0;
}
