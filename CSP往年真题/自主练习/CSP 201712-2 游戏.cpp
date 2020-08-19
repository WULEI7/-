#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	queue<int> q;
	int n,k,baoshu=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		q.push(i);
	while(q.size()>1)
	{
		int temp=q.front();
		q.pop();
		if(baoshu%k!=0&&baoshu%10!=k)
			q.push(temp);
		baoshu++;
	}
	printf("%d\n",q.front());
	return 0;
}
