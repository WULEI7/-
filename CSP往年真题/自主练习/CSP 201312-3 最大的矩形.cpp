#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int a[1005],n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int high=a[i];
		for(int j=i;j<n;j++)
		{
			if(a[j]<high)
				high=a[j];
			int s=(j-i+1)*high;
			if(s>ans)
				ans=s;
		}
	}
	printf("%d\n",ans);
	return 0;
}
