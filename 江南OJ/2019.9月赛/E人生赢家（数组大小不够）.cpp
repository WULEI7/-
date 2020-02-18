#include <bits/stdc++.h>
using namespace std;
int b[100000000];
int main()
{
	int n,m,i,j,begin,end,ans=0,temp=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&begin,&end);
		for(j=begin-1;j<=end-1;j++)
			b[j]=1;
	}
	for(i=0;i<n;i++)
	{
		if(b[i]==0) temp++;
		else temp=0;
		if(temp>ans) ans=temp;
	}
	printf("%d",ans);
	return 0;
}
