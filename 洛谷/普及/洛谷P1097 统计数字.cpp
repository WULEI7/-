#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<int,int> cnt;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n;
	while(n--)
	{
		cin>>m;
		cnt[m]++;
	}
	map<int,int>::iterator it;
	for(it=cnt.begin();it!=cnt.end();it++)
		printf("%d %d\n",it->first,it->second);
	return 0;
}
