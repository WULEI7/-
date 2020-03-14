#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[10000];
int main()
{
	std::ios::sync_with_stdio(false);
	int n,q,x,k=1;
	while(cin>>n>>q)
	{
		if(n==0) break;
		printf("CASE# %d:\n",k++);
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		while(q--)
		{
			cin>>x;
			int i;
			for(i=0;i<n;i++)
				if(x==a[i])
				{printf("%d found at %d\n",x,i+1);break;}
			if(i==n) printf("%d not found\n",x);
		}
	}
	return 0;
}
