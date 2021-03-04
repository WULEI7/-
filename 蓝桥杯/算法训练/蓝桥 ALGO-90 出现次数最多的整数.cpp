#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,ans,maxcnt=1,cnt=1,a[21];
	cin>>n;
	if(n<=0) return 0; 
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ans=a[0];
	for(int i=0;i<n-1;i++)
	{
		if(a[i]==a[i+1])
		{
			cnt++;
			if(cnt>maxcnt)
			{
				maxcnt=cnt;
				ans=a[i];
			}
		}
		else
			cnt=1;
	}
	cout<<ans<<endl;
	return 0;
}
