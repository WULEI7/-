#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		double m;
		cin>>n>>m;
		printf("Circus Act %d:\n",t);
		if(n==1||n*0.5<=m/5)//n=1的情况不能忽略 
			printf("Chester can do it!\n\n");
		else
			printf("Chester will fail!\n\n");
	}
	return 0;
}
