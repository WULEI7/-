#include <stdio.h>
int main()
{  
	int i,a[10],sum=0,count=0;
	
	for (i=0;i<10;i++)
    scanf("%d",&a[i]);
  	for(i=0;i<10;i++)
   	{
		if(a[i]>=0){
		sum+=a[i];
		count++;}
   	}
    printf("%d %d\n",sum,count);
    return 0;
}
