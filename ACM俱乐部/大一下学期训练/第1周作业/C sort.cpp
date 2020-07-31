#include <iostream> 
#include <algorithm>
using namespace std;
int num[1000005];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n);
		for(int i=n-1;i>n-m;i--)
			printf("%d ",num[i]);
		printf("%d\n",num[n-m]);
	}
	return 0;
}
