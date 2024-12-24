#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,N,q,o,a,P=-1;
queue<int> Q;
int main()
{
	cin>>n>>N>>q;
	while(q--)
	{
		cin>>o>>a;
		if(o==0)
		{
			if(P==a)
				continue;
			else
			{
				P=a;
				cout<<0<<" "<<a<<endl;
			}
		}
		else
		{
			if(P==a)
				continue;
			else
				cout<<1<<" "<<a<<endl;
		}
	}	
	return 0;
}