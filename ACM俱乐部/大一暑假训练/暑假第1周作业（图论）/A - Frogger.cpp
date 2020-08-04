#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
double x[201],y[201],map[201][201];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=1,n;
	while(cin>>n)
	{
		if(n==0) break;
		memset(map,0,sizeof(map)); 
		for(int i=1;i<=n;i++)
			cin>>x[i]>>y[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				map[i][j]=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					map[i][j]=min(map[i][j],max(map[i][k],map[k][j]));//Floyd算法，注意这里是求最短的最长边 
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",t,map[1][2]);
		t++;
	}
	return 0;
}
