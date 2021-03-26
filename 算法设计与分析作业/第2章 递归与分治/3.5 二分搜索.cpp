#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
int n,x,num[100005];
int BiSearch(int num[],int x,int n)
{
	int left=1,right=n;
	while(left<=right)
	{
		for(int i=left;i<=right;i++)
			cout<<num[i]<<" ";
		cout<<endl;
		if(x<num[left]||x>num[right])
			return 0;
		int mid=(left+right)/2;
		if(x==num[mid])
			return mid;
		if(x>num[mid])
			left=mid+1;
		if(x<num[mid])
			right=mid-1;
	}
	return 0;
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
		num[++pos]=t;
	cin>>x;
	n=pos;
	int find=BiSearch(num,x,n);
	cout<<find<<endl;
	return 0;
}
