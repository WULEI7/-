#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m,s;
	scanf("%d %d %d",&n,&m,&s);
	if(2*m*s<n)
		printf("hai sheng %d mi! jia you ya!",n-m*s);
	else
		printf("hai sheng %d mi! chong ya!",n-m*s);
	return 0;
}
