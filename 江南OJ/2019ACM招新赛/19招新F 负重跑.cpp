#include <bits/stdc++.h>
using namespace std;
int main()
{
	int dis,wei,d[10],w[10];
	cin>>dis>>wei;
	for(int i=0;i<10;i++)
		cin>>d[i]>>w[i];
	for(;dis>0;dis--)
	{
		wei+=dis;
		for(int i=0;i<10;i++)
		{
			if(d[i]==dis) wei-=w[i];
			if(wei<0) wei=0;
		}
	}
	cout<<wei;
	return 0;
}
