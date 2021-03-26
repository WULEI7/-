#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
struct state
{
	int temp,step;//temp是当前的和，step就是当前搜索的步数，也就是当前需要的数字数量 
	//vector<int> v;
};
int main()
{
	int n,a[105],ans;
	//vector<int> out;
	cin>>n;
	int num=sqrt(n);
	for(int i=1;i<=num;i++)
		a[i]=i*i;
	queue<state> q;//BFS的队列 
	for(int i=1;i<=num;i++)
	{
		state t;
		t.temp=a[i];
		t.step=1;
		//t.v.push_back(a[i]);
		q.push(t);
	}
	while(!q.empty())
	{
		state s=q.front();
		q.pop();
		if(s.temp==n)
		{
			ans=s.step;
			//int size=s.v.size();
			//for(int i=0;i<size;i++)
			//	out.push_back(s.v[i]);
			break;
		}
		for(int i=1;i<=num;i++)
			if(s.temp+a[i]<=n)
			{
				state t;
				t.temp=s.temp+a[i];
				t.step=s.step+1;
				//t.v=s.v;
				//t.v.push_back(a[i]);
				q.push(t);
			}
	}
	printf("%d\n",ans);
	//printf("%d=%d",n,out[0]);
	//for(int i=1;i<out.size();i++)
	//	printf("+%d",out[i]);
	return 0;
}
