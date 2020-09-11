#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int l,n,a,maxn=0,minn=0;
	cin>>l>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		maxn=max(maxn,max(a,l+1-a));
		minn=max(minn,min(a,l+1-a));
	}
	printf("%d %d\n",minn,maxn);
	return 0;
}
