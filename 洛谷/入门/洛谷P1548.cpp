#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,k,l,a=0,b=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			for(k=i;k<=n;k++)
				for(l=j;l<=m;l++)
				{
					if(k-i==l-j) a++;
					else b++;
				}
	printf("%d %d",a,b);
	return 0;
}
