#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,a[100005],ans=0,cnt=0,temp=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
			ans++;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
			cnt++;
		if(a[i]==0)
			cnt--;
		if(cnt<0)
			cnt=0;
		if(cnt>temp)
			temp=cnt;
	}
	cout<<ans+temp<<endl;
	return 0;
}
