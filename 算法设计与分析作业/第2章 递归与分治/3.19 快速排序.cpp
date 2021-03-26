#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

void swap(int &a,int &b)
{
	if(a==b) return;
	a=a^b;
	b=a^b;
	a=a^b;
}

int partition(int a[],int l,int r)//¸ô°å 
{
	int i=l-1;
	for(int j=l;j<r;j++)
		if(a[j]<a[r])
		{
			i++;
			swap(a[i],a[j]);
		}
	swap(a[i+1],a[r]);
	return i+1;
}
void quicksort(int a[],int l,int r,int &time)//¿ìÅÅ 
{
	time++;
	if(l<r)
	{
		int m=partition(a,l,r);
		quicksort(a,l,m-1,time);
		quicksort(a,m+1,r,time);
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	stringstream ss;
	string s;
	getline(cin,s);
	ss<<s;
	int n=0,t,a[1005],time=0;
	while(ss>>t)
		a[n++]=t;
	quicksort(a,0,n-1,time);
	cout<<time<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
