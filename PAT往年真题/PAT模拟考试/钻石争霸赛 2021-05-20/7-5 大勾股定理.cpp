#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	/*
	for(int i=1;;i++)
	{
		int a=0,b=0;
		for(int j=i;j<=i+n;j++)
			a+=j*j;
		for(int j=i+n+1;j<=i+2*n;j++)
			b+=j*j;
		if(a==b)
		{
			printf("%d^2",i);
			for(int j=i+1;j<=i+n;j++)
				printf(" + %d^2",j);
			printf(" =\n");
			printf("%d^2",i+n+1);
			for(int j=i+n+2;j<=i+2*n;j++)
				printf(" + %d^2",j);
			printf("\n");
			break;
		}
	}
	*/
	//找规律，第一项总为n*(2*n+1) 
	int i=n*(2*n+1);
	printf("%d^2",i);
	for(int j=i+1;j<=i+n;j++)
		printf(" + %d^2",j);
	printf(" =\n");
	printf("%d^2",i+n+1);
	for(int j=i+n+2;j<=i+2*n;j++)
		printf(" + %d^2",j);
	printf("\n");
	return 0;
}
