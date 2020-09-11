#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int k,n,tot=0,a[300005],b[300005];
vector<int> ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>k;
	for(int T=1;T<=k;T++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int maxn=a[n-1],temp=n-1;
		b[n-1]=0;
		for(int i=n-2;i>0;i--)
		{
			int flag=1;
			if(a[i]>maxn)
			{
				maxn=a[i];
				temp=i;
				flag=0;
			}
			if(flag==0)
				b[i]=0;
			else if(flag==1)
				b[i]=temp;
		}
		set<int> s;
		s.insert(a[0]);
		for(int i=1;i<n-1;i++)
		{
			int mid=1999999999;
			set<int>::iterator it=s.upper_bound(a[i]);
			if(it!=s.end())
				mid=*it;
			s.insert(a[i]);
			if(b[i]==0) continue;
			if(mid<a[b[i]])
			{
				tot++;
				ans.push_back(T);
				break;
			}
		}
	}
	cout<<tot<<endl;
	int size=ans.size();
	for(int i=0;i<size;i++)
		cout<<ans[i]<<endl;
	return 0;
}
