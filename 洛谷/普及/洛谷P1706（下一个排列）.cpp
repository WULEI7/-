#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,p[9];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		p[i]=i+1;
	do 
	{
		for(i=0;i<n;i++)
			printf("%5d",p[i]);
		printf("\n");
	}while(next_permutation(p,p+n));//用do-while否则不会输出原始排列 
	return 0;
}
