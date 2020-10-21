#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,baoshu=1;
	queue<int> q;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		q.push(i);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(baoshu%m==0)
		{
			printf("%d",temp);
			if(q.size()>0)
				printf(" ");
		}
		else
			q.push(temp);
		baoshu++;
	}
	printf("\n");
	return 0;
}
