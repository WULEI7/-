#include <iostream>
#include <cstdio>
using namespace std;
int a[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		int maxn=-1999999999,dis=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>maxn)
				maxn=a[i];
			if(maxn-a[i]>dis)
				dis=maxn-a[i];
		}
		if(dis==0)
		{
			cout<<0<<endl;
			continue;
		}
		int temp=1,cnt=0;
		while(dis>0)
		{
			cnt++;
			dis-=temp;
			temp*=2;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
