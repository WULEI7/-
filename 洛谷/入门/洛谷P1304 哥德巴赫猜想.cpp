#include <bits/stdc++.h>
using namespace std;
int isprime(int x)
{
	int i,flag=1;
	if(x==2) return 1;
	else if(x%2==0) return 0;
	else for(i=3;i*i<=x;i++)
		if(x%i==0)
		{
			flag=0;break;
		}
	return flag;
}
int main()
{
	int i,j,n;
	cin >> n;
	for(i=4;i<=n;i+=2)
	{
		for(j=2;;j++)
			if(isprime(j)==1&&isprime(i-j)==1)
			{
				printf("%d=%d+%d",i,j,i-j);break;
			}
			printf("\n");
	}
	return 0;
}
