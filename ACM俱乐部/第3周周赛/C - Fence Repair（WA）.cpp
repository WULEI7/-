#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[20005];
long long ans=0;
void cut(int l,int r)
{
	if(l>=r) return;
	int ltot=0,rtot=0,left=l,right=r;
	while(left<=right)
	{
		if(ltot<=rtot)
			ltot+=a[left++];
		else
			rtot+=a[right--];
	}
	ans=ans+ltot+rtot;
	cut(l,left-1);
	cut(right+1,r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cut(0,n-1);
	cout<<ans<<endl;
	return 0;
}
