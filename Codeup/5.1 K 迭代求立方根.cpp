#include<stdio.h>
int main(){
	double x;
	int n; 
	while(scanf("%lf%d",&x,&n)!=EOF){
		double y[100]={0};
		y[0]=x;
		if(n==0){
			printf("%.6f\n",y[n]); 
			continue;
		}
		for(int i=1;i<=n;i++){
			y[i]=y[i-1]*2/3+x/(3*y[i-1]*y[i-1]);
		}
		printf("%.6f\n",y[n]); 
	}
	return 0;
} 
