#include <iostream>
#include <cstdio>
#include <sstream>
int cnt[100005];
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t,minn=100000,maxn=0,a,b;
	string s;
	stringstream ss;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		getline(cin,s);
		ss.clear();
		ss<<s;
		while(ss>>t)
		{
			cnt[t]++;
			if(t<minn) minn=t;
			if(t>maxn) maxn=t;
		}
	}
	for(int i=minn;i<=maxn;i++)
	{
		if(cnt[i]==0) a=i;
		if(cnt[i]==2) b=i;
	}
	printf("%d %d",a,b);
	return 0;
}
