#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
const int maxn=1000005;
int p[maxn],size=0;
void prime()
{
	bool g[maxn];
	for(int i=2;i<maxn;i++)
		g[i]=true;
	for(int i=2;i<maxn;i++)
		if(g[i])
			for(int j=2*i;j<maxn;j+=i)
				g[j]=false;
	int j=0;
	for(int i=2;i<maxn;i++)
		if(g[i])
			p[j++]=i;
	size=j;
}//生成素数表 

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,ans=2;
	cin>>a>>b;
	prime();
	//for(int i=0;i<10;i++)
	//	cout<<p[i]<<endl;
	if(a==1&&b==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	for(int i=a;i<=b;i++)
	{
		if(i==1) continue;
		int find=lower_bound(p,p+size,i)-p;
		if(p[find]==i) continue;
		int cnt=2;
		int s=sqrt(i);
		for(int j=2;j<=s;j++)
			if(i%j==0)
			{
				if(j*j==i)
					cnt++;
				else
					cnt+=2;
			}
		if(cnt>ans)
			ans=cnt;
	}
	cout<<ans<<endl;
	return 0;
}
