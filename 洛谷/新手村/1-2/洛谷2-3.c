#include<stdio.h>
int main(){
	int n,i,c=0,m=0;
	for (i=1;i<=12;i++){
		scanf("%d",&n);
		m+=300;
		if (m<n){
			printf("-%d",i);
			return 0;
		}
		m-=n;
		c+=m/100;
		m%=100;
	}
	printf("%d",c*120+m);
	return 0;
}
