#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int cnt=0,temp=1;
		queue<int> q;
		while(n>0)
		{
			if(n%10)
			{
				cnt++;
				q.push(n%10*temp);
			}
			n/=10;
			temp*=10;
		}
		printf("%d\n",cnt);
		printf("%d",q.front());
		q.pop();
		while(!q.empty())
		{
			printf(" %d",q.front());
			q.pop();
		}
		printf("\n");
	}
	return 0;
}
