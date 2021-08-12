#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int main()
{
	int n,a[1005],ans;
	cin>>n;
	int num=sqrt(n);
	for(int i=1;i<=num;i++)
		a[i]=i*i;
	queue<pair<int,int> > q;//BFSµÄ¶ÓÁÐ 
	q.push({n,0});
	while(1)
	{
		pair<int,int> s=q.front();
		q.pop();
		for(int i=1;i<=num;i++)
		{
			if(s.first==a[i])
			{
				ans=s.second+1;
				goto label;
			}
			if(s.first>a[i])
			{
				pair<int,int> t={s.first-a[i],s.second+1};
				q.push(t);
			}
		}
	}
	label:
		printf("%d\n",ans);
	return 0;
}
