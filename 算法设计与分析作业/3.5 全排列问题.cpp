#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;
int n,a[100005];
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
void Permutation(int a[],int k,int m)
{
	if(k==m)
	{
		for(int i=0;i<=m;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=k;i<=m;i++)
		{
			swap(a[i],a[k]);
			Permutation(a,k+1,m);
			swap(a[i],a[k]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,pos=0;
	string s;
	stringstream ss;
	getline(cin,s);
	ss<<s;
	while(ss>>t)
		a[pos++]=t;
	n=pos;
	sort(a,a+n);
	Permutation(a,0,n-1);
	return 0;
}
