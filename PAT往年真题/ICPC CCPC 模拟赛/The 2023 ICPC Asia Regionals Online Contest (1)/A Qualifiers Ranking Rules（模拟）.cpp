#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
queue<string> A,B,C;
set<string> a,b,c;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n;
	string s;
	cin>>m>>n;
	while(m--)
	{
		cin>>s;
		if(!a.count(s))
		{
			a.insert(s);
			A.push(s);
		}
	}
	while(n--)
	{
		cin>>s;
		if(!b.count(s))
		{
			b.insert(s);
			B.push(s);
		}
	}
	while(A.size()&&B.size())
	{
		C.push(A.front());
		A.pop();
		C.push(B.front());
		B.pop();
	}
	if(A.size())
	{
		while(A.size())
		{
			C.push(A.front());
			A.pop();
		}
	}
	if(B.size())
	{
		while(B.size())
		{
			C.push(B.front());
			B.pop();
		}
	}
	//cout<<"ÅÅÃû"<<endl;
	while(C.size())
	{
		if(!c.count(C.front()))
		{
			c.insert(C.front());
			cout<<C.front()<<endl;
		}
		C.pop();
	}
	return 0;
}
