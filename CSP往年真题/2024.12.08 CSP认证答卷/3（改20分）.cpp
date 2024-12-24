#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
int n,N,q,o,a,cache=-1;
int write=0;
int main()
{
	cin>>n>>N>>q;
	while(q--)
	{
		cin>>o>>a;
		if(o==0)
		{
			//if(cache==a)
			//	continue;
			if(cache!=a)
			{
				if(write)
				{
					cout<<1<<" "<<cache<<endl;
					write=0;
				}
				cache=a;
				cout<<0<<" "<<a<<endl;
			}
		}
		else//o==1
		{
			if(cache==a)
			{
				write=1;
				//continue;
			}
			else
			{
				if(write)
				{
					cout<<1<<" "<<cache<<endl;
					write=0;
				}
				cache=a;
				write=1;
				cout<<0<<" "<<a<<endl;
			}
		}
		//cout<<"cache "<<cache<<endl;
		//cout<<"write "<<write<<endl;
	}
	return 0;
}
