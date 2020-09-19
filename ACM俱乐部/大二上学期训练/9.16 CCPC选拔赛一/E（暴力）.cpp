#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[100005],ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;)
	{
		if(a[i]==0)
		{
			i++;
			continue;
		}
		for(int j=i;j<n;j++)
		{
			if(a[j]>0)
				a[j]--;
			else
				break;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
