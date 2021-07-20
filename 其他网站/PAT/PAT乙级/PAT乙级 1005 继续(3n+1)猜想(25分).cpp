#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[105],flag[105]={0};
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		int t=a[i];
		while(t!=1)
		{
			if(t%2==1)
				t=(t*3+1)/2;
			else
				t=t/2;
			for(int j=0;j<n;j++)
				if(a[j]==t)
					flag[j]=1;
		}
	}
	int pos=0;
	for(int i=n-1;i>=0;i--)
		if(flag[i]==0)
		{
			cout<<a[i];
			pos=i;
			break;
		}
	for(int i=pos-1;i>=0;i--)
		if(flag[i]==0)
			cout<<" "<<a[i];
	cout<<endl;
	return 0;
}
