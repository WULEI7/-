#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	if(n*k==m)
		printf("zheng hao mei ren %d!",k);
	else if(n*k<m)
		printf("hai sheng %d!",m-n*k);
	else
		printf("hai cha %d!",n*k-m);
	return 0;
}
