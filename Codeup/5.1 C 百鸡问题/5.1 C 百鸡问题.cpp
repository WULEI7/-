#include<stdio.h>
int main(){
	double p1=5;
	double p2=3;
	double p3=1.0/3.0;
	double n;
	while(scanf("%lf",&n)!=EOF){
		int x=0;
		int y=0;
		int z=0;
		if(n<100*p3){
			continue;
		}
		else{
			z=100;
			while(x*p1+y*p2+z*p3<=n){//对x的改动 
				while(x*p1+z*p3+y*p2<=n){//对y和z的改动 
					printf("x=%d,y=%d,z=%d\n",x,y,z);
					z--;
					if(z<0) break;
				    y++;
				}
				x++;
				y=0;
				z=100-x-y;
				if(z<0) break;
			}
		}
	}
	return 0;
}
