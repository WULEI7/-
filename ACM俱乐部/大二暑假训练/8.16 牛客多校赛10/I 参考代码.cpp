#include <cstdio>
using namespace std;
int n,m,k,msk;
int main()
{
	scanf("%d",&n);
	while (m*m<n)
		m++;
	msk=(1<<m)-1;
	k=(n+m-1)/m;
	for (int i=0;i<(1<<n);i++)
	{
		int v=__builtin_popcount(i)&1;
		for (int j=0;j<k;j++)
			if (((i>>j*m)&msk)==0)
			{
				v^=1;
				break;
			}
		printf("%d",v);
	}
	printf("\n");
	return 0;
}
