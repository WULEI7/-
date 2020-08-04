#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int n;
int main()
{
	while(cin>>n)
	{
		queue<int> q,q1;
		stack<int> s;
		int x,a[10000];
		for(int i=0;i<n;i++)
			scanf("%1d",&a[i]);
		for(int i=0;i<n;i++)
		{
			scanf("%1d",&x);
			q.push(x);
			q1.push(x);
		}
		int k=0;
		while(!q.empty()&&k<n)
		{
			s.push(a[k++]);
			while(!s.empty()&&!q.empty()&&s.top()==q.front())
			{
				s.pop();
				q.pop();
			}
		}
		if(!q.empty())
		{
			cout<<"No."<<endl;
			cout<<"FINISH"<<endl;
		}
		else
		{
			cout<<"Yes."<<endl;
			int k=0;
			while(!q1.empty()&&k<n)
			{
				s.push(a[k++]);
				cout<<"in"<<endl;
				while(!s.empty()&&!q1.empty()&&s.top()==q1.front())
				{
					s.pop();
					q1.pop();
					cout<<"out"<<endl;
				}
			}
			cout<<"FINISH"<<endl;
		}
	}
	return 0;
}
