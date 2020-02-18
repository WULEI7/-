#include <stdio.h>
int main()
{
	int i,fibo[20];
	fibo[0]=1;fibo[1]=1;
    for(i=2;i<20;i++)
    fibo[i]=fibo[i-2]+fibo[i-1];
	printf("Fibonacci数列的前20项：\n");
    for(i=0;i<20;i++)
    {
    	printf("%-10d",fibo[i]);
    	if(i%4==3) printf("\n");
	}
 return 0;
}
