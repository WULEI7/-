#include <stdio.h>
int main()
{
	int a,s=0;
	while(a>=0)
	{
		scanf("%d",&a);
		if(a<60) s++;
	}
	printf("%d",s-1); 
	return 0;
}

