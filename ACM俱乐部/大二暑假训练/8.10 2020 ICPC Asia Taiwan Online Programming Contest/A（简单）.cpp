#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int x,y;
	cin>>x>>y;
	while(y>0)
	{
		cout<<x<<" "<<y<<endl;
		y--;
	}
	while(x>0)
	{
		cout<<x<<" "<<y<<endl;
		x--;
	}
	for(int i=0;i<=9;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<=9;j++)
				cout<<i<<" "<<j<<endl;
		}
		else
		{
			for(int j=9;j>=0;j--)
				cout<<i<<" "<<j<<endl;
		}
	}
	return 0; 
}
