#include <bits/stdc++.h>
using namespace std;
int isleap(int x)
{
	if((x%100!=0&&x%4==0)||x%400==0)
		return 1;
	else return 0;
}
int main()
{
	int i,n,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(isleap(x)==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
