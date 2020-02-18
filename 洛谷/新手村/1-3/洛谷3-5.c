#include<stdio.h>
int cal(int x, int i){
	int c=0;
	while (x!=0){
		if (x%10==i)
			c++;
		x /= 10;
	}
	return c;
}

int main(){
	int i,n,x,c=0;
	scanf("%d %d",&n,&x);
	for (i=1;i<=n;i++){
		c+=cal(i,x);
	}	
	printf("%d",c);
	return 0;
} 
