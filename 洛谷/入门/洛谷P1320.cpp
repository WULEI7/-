#include <bits/stdc++.h>
using namespace std;
int a[40000];
int main()
{
	int i=0,temp=1,sum=0;
	while(scanf("%1d",&a[i])==1)
		i++;
	sum=i;
	cout << sqrt(sum);
	if(a[0]==1) cout << " 0";
	for(i=0;i<sum-1;i++)
	{
		if(a[i+1]==a[i]) temp++;
		else
		{
			printf(" %d",temp);
			temp=1;
		}
	}
	printf(" %d",temp);
	return 0;
}
