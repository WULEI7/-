#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,a,maxn=0,minn=100;
	double sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		sum+=a;
		if(a>maxn) maxn=a;
		if(a<minn) minn=a;
	}
	printf("%d\n%d\n%.2f\n",maxn,minn,sum/n);
	return 0;
}
