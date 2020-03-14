#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int p;
	int d;
	friend bool operator<(node x,node y)
	{
		if(x.p==y.p)
			return x.d>y.d;
		else
			return x.p>y.p;
	}
};
int main()
{
	int t,i,j,n;
	struct node temp;
	cin>>t;
	int flag;
	while(t--)
	{
		flag=1;
		priority_queue<node>m;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>temp.p>>temp.d;
			m.push(temp);
		}
		while(!m.empty())
		{
			temp=m.top();
			m.pop();
			if(flag%2!=0)
			{
				temp.p+=temp.d;
				m.push(temp);
			}
			flag+=1;
		}
		cout<<temp.p<<endl;
	}
	return 0;
}
