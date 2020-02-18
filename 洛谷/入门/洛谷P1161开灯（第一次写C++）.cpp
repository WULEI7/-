#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,t,i,j,d[2000001]={0};
	double a;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> a >> t;
		for(j=1;j<=t;j++)
			d[(int)(a*j)]++;
	}
	for(i=1;i<2000001;i++)
	{
		if(d[i]%2==1)
		{
			cout << i;
			break;
		}
	}
	return 0;
}
