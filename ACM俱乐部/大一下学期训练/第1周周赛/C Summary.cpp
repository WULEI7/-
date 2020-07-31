#include <cstdio>
#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	long long a[101],b[10000];
	while(scanf("%d",&n)==1)
	{
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			ans+=a[i]*(n-1);
		}
		if(n>2)
		{
			int k=0;
			for(int i=0;i<n-1;i++)
				for(int j=i+1;j<n;j++)
					b[k++]=a[i]+a[j];
			sort(b,b+k);
			for(int i=1;i<k;i++)
				if(b[i]==b[i-1])
					ans-=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
