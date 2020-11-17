#include <iostream>
#include <cstdio>
#include <map>
long long a[200005];
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	map<long long,int> mp;
	int n,pos=0,ans=0;
	long long t;
	cin>>n;
	mp[0]=1;//需要判断0 
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=t+a[i-1];//前缀和 
		if(mp.count(a[i]))
		{
			ans++;
			mp.clear();
			mp[0]=1;//仍然需要判断0 
			a[i]=t;//当前位置之前已被破坏 
		}
		mp[a[i]]=1;
	}
	cout<<ans<<endl;
	return 0;
}
