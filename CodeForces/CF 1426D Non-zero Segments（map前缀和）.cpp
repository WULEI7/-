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
	mp[0]=1;//��Ҫ�ж�0 
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=t+a[i-1];//ǰ׺�� 
		if(mp.count(a[i]))
		{
			ans++;
			mp.clear();
			mp[0]=1;//��Ȼ��Ҫ�ж�0 
			a[i]=t;//��ǰλ��֮ǰ�ѱ��ƻ� 
		}
		mp[a[i]]=1;
	}
	cout<<ans<<endl;
	return 0;
}
