#include <stdio.h>
int main()
{
	int n,a,b=0,s=0;
	for(n=0;n<1000;n++){
		a=n;
		while(a!=0){
			b=b*10+a%10;
			a=a/10;}
		if(n==b){
			printf("%3d ",n);
			s++;
			if(s%10==0) printf("\n");}
		b=0;
	}
	return 0;
}
