#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,k,n,a,mid;
	cin>>t;
	while(t--)
	{
		cin>>k>>n;
		cout<<k<<" "<<(n+1)/2<<endl;
		priority_queue<int> L;
		priority_queue<int,vector<int>,greater<int> > G;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			if(i==1)
			{
				mid=a;
				cout<<a<<" ";
				continue;
			}
			if(a<mid)
				L.push(a);
			else
				G.push(a);
			if(L.size()-G.size()==2)
			{
				G.push(mid);
				mid=L.top();
				L.pop();
			}
			else if(G.size()-L.size()==2)
			{
				L.push(mid);
				mid=G.top();
				G.pop();
			}
			if(i%2==1)
				cout<<mid<<" ";
			if((i+1)%20==0)
				cout<<endl;
		}
		if((n+1)%20!=0)
			cout<<endl;
	}
	return 0;
}
