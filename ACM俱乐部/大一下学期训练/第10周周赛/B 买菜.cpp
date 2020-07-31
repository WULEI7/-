#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n;
	double m,minn=100,temp;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		double a,b;
		cin>>a>>b;
		temp=a/b;
		if(temp<minn)
			minn=temp;
	}
	printf("%.8f",m*minn);
	return 0;
}
