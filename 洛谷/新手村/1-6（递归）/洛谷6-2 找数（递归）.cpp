#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[20];
int isprime(int x)
{
	if(x==2) return 1;
	else if(x%2==0) return 0;
	for(int i=3;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}
void dfs(int wz,int sum,int cur)
{
	if(cur==k)
	{if(isprime(sum)) ans++;}
	else for(int i=wz;i<n;i++)
	     	dfs(i+1,sum+a[i],cur+1);
	return;
}
int main()
{
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	dfs(0,0,0);
	cout << ans;
	return 0;
}
