#include <stdio.h>
#define num(b) sizeof(b)/sizeof(b[0])   //利用带参宏定义数组大小
int main()
{
	char a[]={'B','C','D','E','F','G','H','I','J','K','A'};
    char x;
    int i,n;
    for(n=1;n<=num(a);n++)
	{
		x=a[num(a)-1];
		for(i=num(a)-1;i>=1;i--)
			a[i]=a[i-1];
		a[0]=x;
		for(i=0;i<num(a);i++)
        	printf("%c",a[i]);
        	printf("\n");
    }
    return 0;
}
