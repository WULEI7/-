#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,num[100005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	sort(num,num+n);
	if(num[n-1]<num[0]+num[n-2])
	{
		printf("YES\n");
		for(int i=0;i<n;i++)
		{
			printf("%d",num[i]);
			if(i<n-1)
				printf(" ");
		}
		printf("\n");
		return 0;
	}
	else
	{
		int t=num[n-1];
		num[n-1]=num[n-2];
		num[n-2]=t;
		if(num[n-2]<num[n-1]+num[n-3])
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
			{
				printf("%d",num[i]);
				if(i<n-1)
					printf(" ");
			}
		printf("\n");
		return 0;
		}
		printf("NO\n");
	}
	return 0;
}
