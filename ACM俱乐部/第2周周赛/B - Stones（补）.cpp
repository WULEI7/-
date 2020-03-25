#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
struct node
{
	int p,d;
};
bool operator < (node x,node y)
{
	if(x.p==y.p)
		return x.d>y.d;
	else
		return x.p>y.p;
}
int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	struct node temp;
	cin>>t;
	while(t--)
	{
		priority_queue<node> pq;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>temp.p>>temp.d;
			pq.push(temp);
		}
		int flag=1;
		while(!pq.empty())
		{
			temp=pq.top();
			pq.pop();
			if(flag%2)
			{
				temp.p+=temp.d;
				pq.push(temp);
			}
			flag++;
		}
		cout<<temp.p<<endl;
	}
	return 0;
}
