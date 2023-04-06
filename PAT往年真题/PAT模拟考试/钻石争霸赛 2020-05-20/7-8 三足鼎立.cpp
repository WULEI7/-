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
	//测试说明样例4-9包含长度一样的边 
	long long ans=0;//答案最大可能为(10^5)*(10^5-1)/2，超出int范围 
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
