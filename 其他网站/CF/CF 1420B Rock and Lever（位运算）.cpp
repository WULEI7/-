#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	map<int,long long> mp;
	int t,n,a;
	cin>>t;
	while(t--)
	{
		mp.clear();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			int len=0;
			while(a)
			{
				len++;
				a>>=1;
			}//���������ĳ��� 
			mp[len]++;
		}
		long long ans=0;
		for(int i=1;i<=32;i++)
			ans+=mp[i]*(mp[i]-1)/2;//ע�⿪long long 
		cout<<ans<<endl;
	}
	return 0;
}
