#include <stdio.h>
int main()
{
	int a,c,d[1000],i=0;
	scanf("%d",&a);
	if(a==0) printf("0");
	else{
	while(a!=0){
		c=a%2;a=a/2;
		d[i]=c;
		i++;
	}
	for(i--;i>=0;i--)
	printf("%d",d[i]);}
	return 0;
}
