#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
int a[1005],b[1005];

void merge(int a[],int b[],int left,int mid,int right)
{
	int i=left,j=mid+1,k=left;
	while(i<=mid&&j<=right)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=right)
		b[k++]=a[j++];
}

void copy(int a[],int b[],int left,int right)
{
	for(int i=left;i<=right;i++)
		a[i]=b[i];
}

void merge_Sort(int a[],int left,int right,int &time)
{
	time++;
	if(left<right)
	{
		int mid=left+(right-left)/2;
		merge_Sort(a,left,mid,time);
		merge_Sort(a,mid+1,right,time);
		merge(a,b,left,mid,right);//合并到新数组 
		copy(a,b,left,right);//复制到原数组 
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	stringstream ss;
	string s;
	getline(cin,s);
	ss<<s;
	int t,n=0,time=0;
	while(ss>>t)
		a[n++]=t;;
	merge_Sort(a,0,n-1,time);
	cout<<time<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
