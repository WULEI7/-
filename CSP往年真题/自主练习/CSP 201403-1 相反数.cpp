#include <cstdio>
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	int a[505],n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
			for(int j=i+1;j<n;j++)
				if(a[i]==-a[j])
					ans++;
		if(a[i]>0)
			break;
	}
	cout<<ans<<endl;
	return 0;
}
