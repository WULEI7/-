#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[200005],cnt[200005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		memset(cnt,0,sizeof(cnt));
		int temp=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
				temp++;
			if(a[i]!=a[i-1]||i==n-1)
			{
				cnt[temp]++;
				temp=1;
			}
		}
		int maxcnt=0;
		for(int i=0;i<200005;i++)
			if(cnt[i]>0)
				maxcnt=i;
		if(maxcnt<=n/2)
		{
			if(n%2==1)
				cout<<"1"<<endl;
			else
				cout<<"0"<<endl;
		}
		else
			cout<<2*maxcnt-n<<endl;
	}
	return 0;
}
