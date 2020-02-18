#include <stdio.h>
int main()
{
	int n,i,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		if((i%3==0||i%5==0)&&i%7!=0) s++;
	printf("%d",s);
	return 0;
}
