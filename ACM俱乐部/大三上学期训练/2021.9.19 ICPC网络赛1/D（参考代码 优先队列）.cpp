#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
vector<long long> a1[maxn],a2[maxn];
long long arr[maxn];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(arr,0,sizeof(arr));
		long long n,m,l,r,v;
		cin>>n>>m;
		long long ans=0;
		for(int i=1;i<=m;i++)
		{
			cin>>l>>r>>v;
			a1[l+1].push_back(v);
			a2[r+1].push_back(v);
			ans+=(r-l+1)*(r-l)/2*v;
		}
		long long c=0;
		priority_queue<int,vector<int>,greater<int>> que1,que2;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<a1[i].size();j++)
				que1.push(a1[i][j]);
			for(int j=0;j<a2[i].size();j++)
				que2.push(a2[i][j]);
			while(que1.size()>0&&que2.size()>0&&que1.top()==que2.top())
			{
				que1.pop();
				que2.pop();
			}
			if(que1.size()>0)
			{
				c++;
				arr[i]=que1.top();
			}
		}
		printf("Case #%d: ",t);
		if(c!=n-1)
			printf("Gotta prepare a lesson\n");
		else
		{
			for(int i=2;i<=n;i++)
				ans-=arr[i];
			printf("%lld\n",ans);
		}
	}
}
