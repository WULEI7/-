#include <stdio.h>
#include <math.h> 
int main()
{
	int a,b,c,i,j,k,flag=0;
	float m;
	scanf("%d %d %d",&a,&b,&c);
	for(i=123;i<=987;i++)
	{
		m=(float)i/a;
		if(floor(m)!=m) continue;
		j=i/a*b;
		k=i/a*c;
		if((i/100+i/10%10+i%10+j/100+j/10%10+j%10+k/100+k/10%10+k%10==1+2+3+4+5+6+7+8+9)&&((i/100)*(i/10%10)*(i%10)*(j/100)*(j/10%10)*(j%10)*(k/100)*(k/10%10)*(k%10)==1*2*3*4*5*6*7*8*9))
		{printf("%d %d %d\n",i,j,k);flag=1;}
	}
	if(flag==0) printf("No!!!");
	return 0;
}
