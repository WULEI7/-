#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	double t=0,L[10005];
	while(cin>>n>>k)
	{
		for(int i=0;i<n;i++)
		{
			cin>>L[i];
			if(L[i]>t) t=L[i];
		}
		double lb=0,ub=t;
		for(int i=0;i<100;i++)
		{
			double mid=(lb+ub)/2;
			int num=0;
			for(int i=0;i<n;i++)
				num+=(int)(L[i]/mid);
			if(num>=k) lb=mid;
			else ub=mid;
		}
		printf("%.2f\n",floor(ub*100)/100);
	}
	return 0;
}
