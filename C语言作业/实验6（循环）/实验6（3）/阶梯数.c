#include <stdio.h>
int main()
{  
	int m=0; 
	do{
		if(m%2==1&&m%3==2&&m%5==4&&m%6==5&&m%7==0)
		{printf("Number of steps is %d",m);break;}
		m++;
    }
	while(1);
	return 0;
}
