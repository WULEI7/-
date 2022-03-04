#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int m;
	scanf("%d",&m);
	while(m--){
		int n;
		double v;
		double w;
		double p[110];
		scanf("%d%lf%lf",&n,&v,&w);
		for(int i=0;i<n;i++){
			scanf("%lf",&p[i]);
		}
		sort(p,p+n);
		int now=0;
		double vz=0;//当前总体积 
		double wz=0;//当前总浓度 
		if(p[0]>w){
			printf("0 0.00\n");
			continue;
		}
		double t;
		double x=0; 
		for(int i=0;i<n;i++){
			now=i;
			vz=(now+1)*v;
			t=0;
			for(int j=0;j<=now;j++){
				t+=v*(0.01*p[j]);
				//printf("%lf\n",p[j]);
			}
			wz=(t)/(vz);
			//printf("%lf\n",wz);
			if(wz*100>w){
				now--;
				x=1;
				//printf("%d %lf\n",(int)vz,wz);
				break;
			}
		}
		if(x==1){
			vz=(now+1)*v;
			t=t-(v*0.01*p[now+1]);
			wz=t/vz;
			printf("%d %.2f\n",(int)vz,wz);
		}
		else{
			printf("%d %.2f\n",(int)vz,wz);
		}
		

	}
	return 0;
} 
