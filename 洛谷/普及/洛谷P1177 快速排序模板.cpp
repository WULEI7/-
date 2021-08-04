#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,a[100005];
void swap(int &a,int &b)
{
	if(a==b) return;
	a=a^b;
	b=a^b;
	a=a^b;
}
int partition(int a[],int l,int r)
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
void quicksort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=partition(a,l,r);
		quicksort(a,l,m-1);
		quicksort(a,m+1,r);
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	//quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
