#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,p,a[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>p;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	/*
	for(int i=1;i<n;i++)
		if(a[i]==a[i-1])
			while(1);
	*/
	//����˵������4-9��������һ���ı� 
	long long ans=0;//��������Ϊ(10^5)*(10^5-1)/2������int��Χ 
	for(int i=0;i<n;i++)
	{
		int minn=abs(p-a[i]),maxn=p+a[i];
		/*
		int l=upper_bound(a,a+n,minn)-a;
		int r=lower_bound(a,a+n,maxn)-a;
		l=max(i+1,l);
		*/
		int l=upper_bound(a+i+1,a+n,minn)-a;
		int r=lower_bound(a+i+1,a+n,maxn)-a;
		//for(int j=l;j<r;j++)
		//	cout<<a[i]<<" "<<a[j]<<endl;
		ans+=r-l;
	}
	cout<<ans<<endl;
	return 0;
}
