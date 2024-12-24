#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
int n,N,q,o,a;
//int write=0,cache=-1;
//int write[65536],cache[65536];
int main()
{
	cin>>n>>N>>q;
	if(n==1&&N==1)
	{
		int write=0,cache=-1;
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
	}
	else if(n==1)
	{
		int write[65536],cache[65536];
		for(int i=0;i<N;i++)
		{
			write[i]=0;
			cache[i]=-1;
		}
		while(q--)
		{
			cin>>o>>a;
			int index=a%N;
			if(o==0)
			{
				//if(cache==a)
				//	continue;
				if(cache[index]!=a)
				{
					if(write[index])
					{
						cout<<1<<" "<<cache[index]<<endl;
						write[index]=0;
					}
					cache[index]=a;
					cout<<0<<" "<<a<<endl;
				}
			}
			else//o==1
			{
				if(cache[index]==a)
				{
					write[index]=1;
					//continue;
				}
				else
				{
					if(write[index])
					{
						cout<<1<<" "<<cache[index]<<endl;
						write[index]=0;
					}
					cache[index]=a;
					write[index]=1;
					cout<<0<<" "<<a<<endl;
				}
			}
		}
	}
	else if(N==1)
	{
		
	}
	return 0;
}
