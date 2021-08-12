#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int isprime(int n)
{
	if(n<2) return 0;
	int s=sqrt(n);
	for(int i=2;i<=s;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,n1,n2,d;
	vector<int> v;
	while(cin>>n)
	{
		
		if(n<0) break;
		cin>>d;
		v.clear();
		n1=n2=0;
		n1=n;
		while(n)
		{
			v.emplace_back(n%d);
			n/=d;
		}
		int size=v.size();
		//for(int i=size-1;i>=0;i--)
		//	n1=n1*d+v[i];
		for(int i=0;i<size;i++)
			n2=n2*d+v[i];
		if(isprime(n1)&&isprime(n2))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
