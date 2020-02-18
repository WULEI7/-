#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,a,sum=0,flag=0;
	cin >> n;
	while(scanf("%d",&a)==1)
	{
		for(i=0;i<a;i++)
		{
			printf("%d",flag);
			sum++;
			if(sum%n==0) printf("\n");
		}
		flag=!flag;
	}
	return 0;
}
