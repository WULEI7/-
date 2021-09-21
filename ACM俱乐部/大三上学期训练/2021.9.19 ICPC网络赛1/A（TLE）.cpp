#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int num,cnt;
	long long end;
	bool operator < (const node b) const
	{
		return cnt==b.cnt ? num<b.num : cnt>b.cnt;
	}
}p[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k,n;
	long long a,b;
	cin>>k>>n;
	for(int i=0;i<k;i++)
	{
		p[i].num=i;
		p[i].end=0;
		p[i].cnt=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int j=0;j<n;j++)
			if(p[(i+j)%k].end<=a)
			{
				p[(i+j)%k].end=a+b;
				p[(i+j)%k].cnt++;
				break;
			}
	}
	sort(p,p+k);
	int maxcnt=p[0].cnt;
	cout<<p[0].num;
	for(int i=1;i<k;i++)
	{
		if(p[i].cnt==maxcnt)
			cout<<" "<<p[i].num;
		else
			break;
	}
	return 0;
}
