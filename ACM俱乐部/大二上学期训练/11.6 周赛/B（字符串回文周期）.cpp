#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
map<int,int> cnt;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,T;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>T;
		cin>>s;
		int k=n/T,len=s.length(),ans=0;
		for(int i=0;i<T/2;i++)
		{
			cnt.clear();
			for(int j=1;j<=k;j++)
			{
				cnt[s[T*(j-1)+i]]++;
				cnt[s[T*j-1-i]]++;
			}
			int maxn=0;
			map<int,int>::iterator it;
			for(it=cnt.begin();it!=cnt.end();it++)
				if(it->second>maxn)
					maxn=it->second;
			ans+=2*k-maxn;
		}
		if(T%2==1)
		{
			cnt.clear();
			for(int j=T/2;j<len;j+=T)
				cnt[s[j]]++;
			int maxn=0;
			map<int,int>::iterator it;
			for(it=cnt.begin();it!=cnt.end();it++)
				if(it->second>maxn)
					maxn=it->second;
			ans+=k-maxn;
		}
		cout<<ans<<endl;
	}
	return 0;
}
