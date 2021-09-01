#include <cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for (int i=0;i<(1<<n);i++)
		printf("%d",__builtin_popcount(i)&1);
	printf("\n");
	return 0;
}
