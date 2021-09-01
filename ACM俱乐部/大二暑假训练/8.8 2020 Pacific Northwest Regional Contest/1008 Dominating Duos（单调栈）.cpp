#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a;
	cin>>n;
	long long ans=0;
	stack<int> s;
	cin>>a;
	s.push(a);
	for(int i=1;i<n;i++)
	{
		cin>>a;
		int res=s.size();
		while(s.size()&&s.top()<a)
			s.pop();
		ans+=min(res,int(res+1-s.size()));
		s.push(a);
	}
	cout<<ans<<endl;
	return 0;
}
