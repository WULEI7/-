#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[3],ans=0;
	cin>>a[0]>>a[1]>>a[2];
	while((a[0]>0&&a[1]>0||a[1]>0&&a[2]>0||a[2]>0&&a[0]>0)&&a[0]+a[1]+a[2]>=3) 
	{
		sort(a,a+3);
		a[2]-=2;a[1]-=1;
		ans++;
	}
	cout<<ans;
	return 0;
	
}
