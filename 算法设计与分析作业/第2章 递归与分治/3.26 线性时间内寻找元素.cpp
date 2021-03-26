#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;

int flag=1,a[1005];

void Swap(int &a,int &b)//位运算交换两个数 
{
	if(a==b) return;
	a=a^b;
	b=a^b;
	a=a^b;
}

int Partition(int a[],int p,int r,int x)//划分 
{
	int pos=p;
	for(int i=p;i<=r;i++)
		if(a[i]==x)
		{
			pos=i;
			break;
		}
	Swap(a[p],a[pos]);
	int i=p,j=r+1;
	while(true)
	{
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j) break;
		Swap(a[i],a[j]);
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}

int Select(int a[],int p,int r,int k)//Select算法 
{
	int n=r-p+1;
	if(n<5)//待找范围元素少于5个 
	{
		sort(a+p,a+r+1);
		return a[p+k-1];
	}
	for(int i=0;i<=(n-5)/5;i++)//分组时的组的个数为n/5的向下取整 
	{
		sort(a+p+5*i,a+p+5*i+5);
		Swap(a[p+5*i+2],a[p+i]);
	}
	int x=Select(a,p,p+(n-5)/5,(n/5+1)/2);//找中位数的中位数,分组后的中位数取第（num_group/2向上取整）小的元素 
	if(flag==1)
	{
		cout<<x<<endl;
		flag=0;
	}//输出第一次划分找到的基准元素 
	int q=Partition(a,p,r,x);
	int j=q-p+1;
	if(k==j)
		return a[q];
	else if(k<j)
		return Select(a,p,q-1,k);
	else
		return Select(a,q+1,r,k-j);
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	stringstream ss;
	string s;
	getline(cin,s);
	ss<<s;
	int t,k,num=0;
	while(ss>>t)
		a[num++]=t;
	cin>>k;
	int ans=Select(a,0,num-1,k);
	cout<<ans<<endl;
	return 0;
}
