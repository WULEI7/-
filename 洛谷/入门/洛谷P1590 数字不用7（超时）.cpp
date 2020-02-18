#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
	int i,j,t,ans,n;
	for(i=1;i<10000000;i++)
	{		
		t=i;
		while(t)
		{
			if(t%10==7)
			{a[i]=1;break;}
			t/=10;
		}
	}
	cin >> t;
	for(i=0;i<t;i++)
	{
		cin >> n;
		ans=n;
		for(j=1;j<=n;j++)
			if(a[j]==1) ans--;
		printf("%d\n",ans);
	}
	return 0;
}
